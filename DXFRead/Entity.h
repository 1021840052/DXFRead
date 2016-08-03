 #ifndef _ENTITY_H_
 #define _ENTITY_H_
 
 #include <iostream>
 #include <list>
 #include <fstream>
 #include <string>
 using namespace std;
 
 class CEntity
 {
 public:
     CEntity(void);
     ~CEntity(void);
 
     //
     virtual void Show(void) = 0;
 
 private:
 
 };
 
 #endif // _ENTITY_H_