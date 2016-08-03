 #include "Arc.h"

CArc::CArc(void)
{
    m_StartAngle = 0;
    m_EndAngle     = 0;
}

CArc::~CArc(void)
{
}

void CArc::Show( void )
{
    cout<<"-----------------ARC-------------------"<<endl;
    cout<<"Start : "<<m_StartAngle<<endl;
    cout<<"End   : "<<m_EndAngle<<endl;
    cout<<"======================================="<<endl;
}

void CArc::SetStartAngle( double s )
{
    m_StartAngle    = s;
}

void CArc::SetEndAngle( double e )
{
    m_EndAngle    = e;
}