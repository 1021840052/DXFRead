#ifndef _LINE_H_
#define _LINE_H_

#include "Entity.h"

class CLine : public CEntity
{
public:
    CLine(void);
    ~CLine(void);

    // 
    void Show(void);

    // 
    void SetX1(double x);
    void SetY1(double y);
    void SetZ1(double z);
    void SetX2(double x);
    void SetY2(double y);
    void SetZ2(double z);

private:
    // 
    double    m_x1;
    // 
    double    m_y1;
    // 
    double    m_z1;
    // 
    double    m_x2;
    // 
    double    m_y2;
    // 
    double    m_z2;

};

#endif // _LINE_H_