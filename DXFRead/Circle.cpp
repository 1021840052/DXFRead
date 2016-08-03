#include "Circle.h"

CCircle::CCircle(void)
{
    m_x    = m_y = m_z = m_Radius = 0;
}

CCircle::~CCircle(void)
{
}

void CCircle::Show( void )
{
    cout<<"----------------CIRCLE-----------------"<<endl;
    cout<<"Center : ("<<m_x<<","<<m_y<<","<<m_z<<")"<<endl;
    cout<<"Radius : "<<m_Radius<<endl;
    cout<<"======================================="<<endl;
}

void CCircle::SetX( double x )
{
    m_x    = x;
}

void CCircle::SetY( double y )
{
    m_y    = y;
}

void CCircle::SetZ( double z )
{
    m_z    = z;
}

void CCircle::SetRadius( double r )
{
    m_Radius    = r;
}