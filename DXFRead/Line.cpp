#include "Line.h"

CLine::CLine(void)
{
    m_x1 = m_x2 = m_y1 = m_y2 = m_z1 = m_z2 = 0;
}

CLine::~CLine(void)
{
}

void CLine::Show( void )
{
    cout<<"-----------------LINE------------------"<<endl;
    cout<<"Start : ("<<m_x1<<","<<m_y1<<","<<m_z1<<")"<<endl;
    cout<<"End   : ("<<m_x2<<","<<m_y2<<","<<m_z2<<")"<<endl;
    cout<<"======================================="<<endl;
}

void CLine::SetX1( double x )
{
    m_x1    = x;
}

void CLine::SetY1( double y )
{
    m_y1    = y;
}

void CLine::SetZ1( double z )
{
    m_z1    = z;
}

void CLine::SetX2( double x )
{
    m_x2    = x;
}

void CLine::SetY2( double y )
{
    m_y2    = y;
}

void CLine::SetZ2( double z )
{
    m_z2    = z;
}