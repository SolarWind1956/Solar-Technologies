//---------------------------------------------------------------------------
//  *************************************************************************
//  Sergej Edgar Heckel
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  14.05.2001
//  *************************************************************************

#ifndef CoordSysH
#define CoordSysH
#include "Algebra.h"
#include "FormCanv.h"
//---------------------------------------------------------------------------
//  ������ ������ ���������
enum CoordinateSystemClasses {  Cartesian,      /* ��������� */
                                Curvilinear     /* ������������� */ };
//  ���� ������ ���������
enum CoordinateSystemKinds   {  Orthographic,   /* ������������� */
                                Obligue         /* ������������ */  };
//  ���� ������ ���������
enum CoordinateSystemTypes   {  Right,          /* ������ */
                                Left            /* ����� */         };
// ����� "������� ���������"
class CoordinateSystem {
public:
    //
    CoordinateSystemClasses     CSystemClass;   // ����� ������� ���������
    CoordinateSystemKinds       CSystemKind;    // ��� ������� ���������
    CoordinateSystemTypes       CSystemType;    // ��� ������� ���������
    // ���� ����
    TAlgVector BasicVectorX;
    TAlgVector BasicVectorY;
    TAlgVector BasicVectorZ;
    // ���������� ������ ������� ���������
    long double X_Center;
    long double Y_Center;
    long double Z_Center;
    void SetCenterCoordinate(long double X,
                             long double Y,
                             long double Z) {
        X_Center = X; Y_Center = Y; Z_Center = Z;
    };
    // ���������� ���� ������� ���������
    virtual void Draw(TFormCanvas*) = 0;
    // �������� ���� ������� ��������� (������������� ����������� - ������
    //                                  ������� �������)
    // ������ ��� ��
    virtual void RotateAroundOX(long double) = 0;
    // ������ ��� �Y
    virtual void RotateAroundOY(long double) = 0;
    // ������ ��� �Z
    virtual void RotateAroundOZ(long double) = 0;
    virtual void Rotate(long double, long double, long double) = 0;
    virtual TAlgVector VectorCoordinate(TAlgVector) = 0;
    virtual ~CoordinateSystem() {};
};
// _________________________________________________________________
// � � � � � � �    � � � � � � � � �
// _________________________________________________________________
// ����� "��������� ������������� ������� ���������"
class CartesianOrthographicCoordinateSystem : public CoordinateSystem {
public:
    // �����������
    CartesianOrthographicCoordinateSystem(CoordinateSystemTypes enSystemType) {
        // ����� ������� ���������
        CSystemClass = Cartesian;       // ���������
        // ��� ������� ���������
        CSystemKind  = Orthographic;    // ������������ (��� �������������)
        // ��� ������� ���������
        CSystemType  = enSystemType;
        if (enSystemType == Right) {    // ������
            BasicVectorX = TAlgVector(1, 0, 0);
            BasicVectorY = TAlgVector(0, 1, 0);
            BasicVectorZ = TAlgVector(0, 0, 1);
        } else {                        // �����
            BasicVectorX = TAlgVector(1, 0, 0);
            BasicVectorY = TAlgVector(0, 1, 0);
            BasicVectorZ = TAlgVector(0, 0, 1);
        };
    };
    // ���������� ���� ������� ���������
    void Draw(TFormCanvas*);
    // �������� ���� ������� ���������
    // ������ ��� ��
    void RotateAroundOX(long double OX_Angle);
    // ������ ��� �Y
    void RotateAroundOY(long double OY_Angle);
    // ������ ��� �Z
    void RotateAroundOZ(long double OZ_Angle);
    void Rotate(long double OX_Angle = 0.0L,
                long double OY_Angle = 0.0L,
                long double OZ_Angle = 0.0L);
    // ���������� ������������� ������� � ������ ������� ���������
    virtual TAlgVector VectorCoordinate(TAlgVector);
};
#endif
