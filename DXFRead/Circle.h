 #ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Entity.h"

class CCircle : public CEntity
{
public:
    CCircle(void);
    ~CCircle(void);

    // 
    void Show(void);

    // 
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    void SetRadius(double r);

private:
    // 
    double    m_x;
    // 
    double    m_y;
    // 
    double    m_z;
    // 
    double    m_Radius;
};

#endif // _CIRCLE_H_