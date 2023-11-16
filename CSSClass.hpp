#pragma once
/*
  FengYe - CPPML Rewrite Project
  {date} by mxjeonsg
  
  CSSClass.hpp $ CSS Class Object
*/

//General Buffer
static string cbuff = "";
static u32 styCount = 0;

class CSS {
  private:
  string tag = "";
  
  
  public:
  CSS(const string t) {
    ifnotempty(t) {
      //Syntax:
      // tag { styles }
      
    } else throw EmptyArgumentException();
  }
  
  ~CSS(void) {
    tag = "";
  }
};