#ifndef _ARC_H_
#define _ARC_H_

#include "Entity.h"

class CArc : public CEntity
{
public:
    CArc(void);
    ~CArc(void);

    void Show(void);

    void SetStartAngle(double s);
    void SetEndAngle(double e);

private:
    double    m_StartAngle;
    double    m_EndAngle;
};

#endif // _ARC_H_