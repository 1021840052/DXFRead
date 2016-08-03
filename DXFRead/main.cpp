#include "Arc.h"
#include "Line.h"
#include "Circle.h"


int main(int argc, char* argv[])
{
    char            szFileName[_MAX_FNAME];
    int                iGroupCode = 0;
    string            strGroupValue;
    string            strBuffer;
    list<CEntity*>    EntitiesList;

    cout<<"Input a DXF file name :";
    cin>>szFileName;

    CLine*        pLine    = NULL;
    CCircle*    pCircle    = NULL;
    CArc*        pArc    = NULL;

    ifstream    iDxfFile(szFileName);

    if (!iDxfFile.is_open())
    {
        cout<<"Open DXF file "<<szFileName<<" failed!"<<endl;
        return -1;
    }

    while ( !iDxfFile.eof())
    {
        getline(iDxfFile, strBuffer);
        iGroupCode    = atoi(strBuffer.c_str());
        getline(iDxfFile, strGroupValue);

        // Just Read Entities Section.
        if (iGroupCode == 2 && strGroupValue.compare("ENTITIES") == 0)
        {
            getline(iDxfFile, strBuffer);
            getline(iDxfFile, strGroupValue);
            iGroupCode    = atoi(strBuffer.c_str());

            while (strGroupValue.compare("ENDSEC") != 0)
            {
                // Read Line Data
                if (iGroupCode == 0 && strGroupValue.compare("LINE") == 0)
                {
                    pLine    = new CLine;
                    getline(iDxfFile, strBuffer);
                    getline(iDxfFile, strGroupValue);
                    iGroupCode = atoi(strBuffer.c_str());

                    while (iGroupCode)
                    {
                        // 
                        getline(iDxfFile, strBuffer);
                        getline(iDxfFile, strGroupValue);
                        iGroupCode = atoi(strBuffer.c_str());
                        switch(iGroupCode)
                        {
                        case 10: pLine->SetX1(atof(strGroupValue.c_str())); break;
                        case 20: pLine->SetY1(atof(strGroupValue.c_str())); break;
                        case 30: pLine->SetZ1(atof(strGroupValue.c_str())); break;
                        case 11: pLine->SetX2(atof(strGroupValue.c_str())); break;
                        case 21: pLine->SetY2(atof(strGroupValue.c_str())); break;
                        case 31: pLine->SetZ2(atof(strGroupValue.c_str())); break;
                        }
                    }

                    EntitiesList.push_front(pLine);
                }

                // Read Circle Data
                else if (iGroupCode == 0 && strGroupValue.compare("CIRCLE") == 0)
                {
                    pCircle    = new CCircle;
                    getline(iDxfFile, strBuffer);
                    getline(iDxfFile, strGroupValue);
                    iGroupCode = atoi(strBuffer.c_str());

                    while (iGroupCode)
                    {
                        // 
                        getline(iDxfFile, strBuffer);
                        getline(iDxfFile, strGroupValue);
                        iGroupCode = atoi(strBuffer.c_str());
                        switch(iGroupCode)
                        {
                        case 10: pCircle->SetX(atof(strGroupValue.c_str()));        break;
                        case 20: pCircle->SetY(atof(strGroupValue.c_str()));        break;
                        case 30: pCircle->SetZ(atof(strGroupValue.c_str()));        break;
                        case 40: pCircle->SetRadius(atof(strGroupValue.c_str()));    break;
                        }
                    }

                    EntitiesList.push_front(pCircle);
                }

                // Read Arc Data
                else if (iGroupCode == 0 && strGroupValue.compare("ARC") == 0)
                {
                    pArc    = new CArc;
                    getline(iDxfFile, strBuffer);
                    getline(iDxfFile, strGroupValue);
                    iGroupCode = atoi(strBuffer.c_str());

                    while (iGroupCode)
                    {
                        // 
                        getline(iDxfFile, strBuffer);
                        getline(iDxfFile, strGroupValue);
                        iGroupCode = atoi(strBuffer.c_str());
                        switch(iGroupCode)
                        {
                        case 50: pArc->SetStartAngle(atof(strGroupValue.c_str()));    break;
                        case 51: pArc->SetEndAngle(atof(strGroupValue.c_str()));    break;
                        }
                    }

                    EntitiesList.push_front(pArc);
                }

                // Other entities
                else
                {
                    // Move to next two lines
                    getline(iDxfFile, strBuffer);
                    getline(iDxfFile, strGroupValue);
                    /*iGroupCode = atoi(strBuffer.c_str());*/
                }
            }
        }

    }

    // Output Entities
    for (list<CEntity*>::iterator iter = EntitiesList.begin(); 
        iter != EntitiesList.end(); 
        iter++)
    {
        (*iter)->Show();
    }

    return 0;
}