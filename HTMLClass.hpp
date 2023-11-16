#pragma once
/*
  FengYe - CPPML Rewrite Project
  Tuesday, Nov 14, 2023 by mxjeonsg
  
  HTMLClass.hpp $ HTML Class Object
*/


//General buffer
static string buff = "";
static u32 tagCount = 0;

class TagArgs {
  public:
  string
   styles = "", id = "",
   classs = "", content = "",
   href = "";
  u32 height = -69, width = -69;
  
  TagArgs(string cont, string stl = "", string idd = "", string classss = "", string href = "", u32 w = -255, u32 h = -255) {
    if(stl != "") styles = stl;
    if(idd != "") id = idd;
    if(classss != "") classs = classss;
    if(cont != "") content = cont;
    if(w > 0) width = w;
    if(h > 0) height = h;
  }
  
  ~TagArgs(void) {
    styles = "";
    id = "";
    classs = "";
    content = "";
    width = -255;
    height = -255;
  }
};


class HTML {
  private:
  bbool fileExist(const string fname) {
    ifnotempty(fname) {
      bbool res = no;
      FILE* fptr = fopen(fname.c_str(), "r");
      ifnotnull(fptr) res = yes;
      fclose(fptr);
      return res;
    }
    return no;
  }
  
  bbool MobileView = no;
  string charset = "utf-8";
  string title = "Default";
  string lang = "";
  string favicon = "";

  void drawStatistics(void) {
    f32 bufsz = (f32) strlen(buff.c_str()) / 1024;
    bufsz = bufsz > 0 && bufsz < 1 ? 1 : bufsz;
    std::cout <<
    "\n<Buffer Stats>\n"
    "Tags: " << tagCount << "\n"
    "Buffer size: " << bufsz << "kB\n"
    "Total characters: " << strlen(buff.c_str()) << "\n"
    ;
  }
  
  public:
  string const* pubbuffptr = &buff;
  
  ~HTML(void) {
    buff = "";
    charset = "";
    title = "Default";
    lang = "";
    favicon = "";
    tagCount = 0;
    MobileView = no;
  }

  HTML(const string tit, const string fvc, const string l = "en", const bool mobvw = no, const string cset = "utf-8") {
    buff.append(
      "<!DOCTYPE html>\n"
      "<html "
    );
    tagCount++;
    ifnotempty(l) {
      buff.append("lang=\"");
      buff.append(l);
      buff.append("\">\n");
    }
    buff.append("  <head>\n");
    tagCount++;
    ifnotempty(tit) {
      buff.append("    <title>");
      buff.append(tit);
      buff.append("</title>\n");
      tagCount++;
    }
    ifnotempty(fvc) {
      if(fileExist(fvc)) {
        buff.append("    <link rel=\"icon\" type=\"image/x-icon\" href=\"");
        buff.append(fvc);
        buff.append("\">\n");
        tagCount++;
      } else throw
        FileNotFoundException(fvc);
    }
    buff.append("    <meta charset=\"utf-8\"/>\n");
    tagCount++;
    if(mobvw) {
      buff.append("    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
      tagCount++;
    }
    
    buff.append("  </head>\n");
    buff.append("  <body>\n");
    tagCount++;
  }
  
  void flush(void) {
    buff = "";
  }
  
  void export_buff(const string fname) {
    ifnotempty(fname) {
      drawStatistics();
      FILE* fptr = fopen(fname.c_str(), "w+");
      ifnull(fptr) throw
        FileNotFoundException(fname);
      
      const size_t buffsz = strlen(buff.c_str());
      size_t how = fwrite(
        buff.c_str(),
        sizeof(char),
        buffsz,
        fptr
      );
      
      if(how < buffsz) throw
        IOFaultException(FIO_WRITE_NOTWRITTENE);
    } else {
      throw
      EmptyArgumentException();
    }
  }
  
  void export_buff(const u8 ffd) {
    if(ffd > 2) {
      FILE* fptr = fdopen(ffd, "w+");
      if(fptr == NULL) throw
        FileNotFoundException(ffd);
      
      const size_t buffsz = strlen(buff.c_str());
      size_t how = fwrite(
        buff.c_str(),
        sizeof(char),
        buffsz,
        fptr
      );
      
      if(how < buffsz) throw
        IOFaultException(FIO_WRITE_NOTWRITTENE);
    } else {
      throw
      EmptyArgumentException();
    }
  }
  
  void export_buff(FILE* fptr) {
    if(fptr != NULL) {
      const size_t buffsz = strlen(buff.c_str());
      size_t how = fwrite(
        buff.c_str(),
        sizeof(char),
        buffsz,
        fptr
      );
      
      if(how < buffsz) throw
        IOFaultException(FIO_WRITE_NOTWRITTENE);
    } else {
      throw
      NullAsArgumentException();
    }
  }
  
  struct {
    //Heading (1-6)
    void h1(const string cont) {
      ifnotempty(cont) {
        buff.append("    <h1>");
        buff.append(cont);
        buff.append("</h1>");
        tagCount++;
      } else throw EmptyArgumentException();
    }
    
    void h1(const TagArgs* ta) {
      ifnull(ta) throw NullAsArgumentException();
      
      //Tag
      //<h# id class> content
      buff.append("    <h1");
      ifnotempty(ta->styles) {
        buff.append(" style=\"");
        buff.append(ta->styles);
        buff.append("\"");
      }
      ifnotempty(ta->id) {
        buff.append(" id=\"");
        buff.append(ta->id);
        buff.append("\"");
      }
      ifnotempty(ta->classs) {
        buff.append(" class=\"");
        buff.append(ta->classs);
        buff.append("\"");
      }
      buff.append(">");
      buff.append(ta->content);
      buff.append("</h1>\n");
      tagCount++;
    }
    
    void h2(const string cont) {
      ifnotempty(cont) {
        buff.append("    <h2>");
        buff.append(cont);
        buff.append("</h2>");
        tagCount++;
      } else throw EmptyArgumentException();
    }
    
    void h2(const TagArgs* ta) {
      ifnull(ta) throw NullAsArgumentException();
      
      //Tag
      //<h# id class> content
      buff.append("    <h2");
      ifnotempty(ta->styles) {
        buff.append(" style=\"");
        buff.append(ta->styles);
        buff.append("\"");
      }
      ifnotempty(ta->id) {
        buff.append(" id=\"");
        buff.append(ta->id);
        buff.append("\"");
      }
      ifnotempty(ta->classs) {
        buff.append(" class=\"");
        buff.append(ta->classs);
        buff.append("\"");
      }
      buff.append(">");
      buff.append(ta->content);
      buff.append("</h2>\n");
      tagCount++;
    }
    
    void h3(const string cont) {
      ifnotempty(cont) {
        buff.append("    <h3>");
        buff.append(cont);
        buff.append("</h3>");
        tagCount++;
      } else throw EmptyArgumentException();
    }
    
    void h3(const TagArgs* ta) {
      ifnull(ta) throw NullAsArgumentException();
      
      //Tag
      //<h# id class> content
      buff.append("    <h3");
      ifnotempty(ta->styles) {
        buff.append(" style=\"");
        buff.append(ta->styles);
        buff.append("\"");
      }
      ifnotempty(ta->id) {
        buff.append(" id=\"");
        buff.append(ta->id);
        buff.append("\"");
      }
      ifnotempty(ta->classs) {
        buff.append(" class=\"");
        buff.append(ta->classs);
        buff.append("\"");
      }
      buff.append(">");
      buff.append(ta->content);
      buff.append("</h3>\n");
      tagCount++;
    }
    
    void h4(const string cont) {
      ifnotempty(cont) {
        buff.append("    <h4>");
        buff.append(cont);
        buff.append("</h4>");
        tagCount++;
      } else throw EmptyArgumentException();
    }
    
    void h4(const TagArgs* ta) {
      ifnull(ta) throw NullAsArgumentException();
      
      //Tag
      //<h# id class> content
      buff.append("    <h4");
      ifnotempty(ta->styles) {
        buff.append(" style=\"");
        buff.append(ta->styles);
        buff.append("\"");
      }
      ifnotempty(ta->id) {
        buff.append(" id=\"");
        buff.append(ta->id);
        buff.append("\"");
      }
      ifnotempty(ta->classs) {
        buff.append(" class=\"");
        buff.append(ta->classs);
        buff.append("\"");
      }
      buff.append(">");
      buff.append(ta->content);
      buff.append("</h4>\n");
      tagCount++;
    }
    
    void h5(const string cont) {
      ifnotempty(cont) {
        buff.append("    <h5>");
        buff.append(cont);
        buff.append("</h5>");
        tagCount++;
      } else throw EmptyArgumentException();
    }
    
    void h5(const TagArgs* ta) {
      ifnull(ta) throw NullAsArgumentException();
      
      //Tag
      //<h# id class> content
      buff.append("    <h5");
      ifnotempty(ta->styles) {
        buff.append(" style=\"");
        buff.append(ta->styles);
        buff.append("\"");
      }
      ifnotempty(ta->id) {
        buff.append(" id=\"");
        buff.append(ta->id);
        buff.append("\"");
      }
      ifnotempty(ta->classs) {
        buff.append(" class=\"");
        buff.append(ta->classs);
        buff.append("\"");
      }
      buff.append(">");
      buff.append(ta->content);
      buff.append("</h5>\n");
      tagCount++;
    }
    
    void h6(const string cont) {
      ifnotempty(cont) {
        buff.append("    <h6>");
        buff.append(cont);
        buff.append("</h6>");
        tagCount++;
      } else throw EmptyArgumentException();
    }
    
    void h6(const TagArgs* ta) {
      ifnull(ta) throw NullAsArgumentException();
      
      //Tag
      //<h# id class> content
      buff.append("    <h6");
      ifnotempty(ta->styles) {
        buff.append(" style=\"");
        buff.append(ta->styles);
        buff.append("\"");
      }
      ifnotempty(ta->id) {
        buff.append(" id=\"");
        buff.append(ta->id);
        buff.append("\"");
      }
      ifnotempty(ta->classs) {
        buff.append(" class=\"");
        buff.append(ta->classs);
        buff.append("\"");
      }
      buff.append(">");
      buff.append(ta->content);
      buff.append("</h6>\n");
      tagCount++;
    }
    
   
    struct { //Anchor (a)
      //As container
      //Start
      void begin(const string href) {
        ifnotempty(href) {
          buff.append("    <a href=\"");
          buff.append(href);
          buff.append("\">\n");
          tagCount++;
        }
      }
      
      void begin(const TagArgs* ta) {
        ifnull(ta) throw NullAsArgumentException();
        buff.append("    <a");
        ifnotempty(ta->styles) {
          buff.append(" style=\"");
          buff.append(ta->styles);
          buff.append("\"");
        }
        ifnotempty(ta->classs) {
          buff.append(" class=\"");
          buff.append(ta->classs);
          buff.append("\"");
        }
        ifnotempty(ta->id) {
          buff.append(" id=\"");
          buff.append(ta->classs);
          buff.append("\"");
        }
        ifnotempty(ta->href) {
          buff.append(" href=\"");
          buff.append(ta->href);
          buff.append("\"");
        }
        buff.append(">");
        tagCount++;
      }
      
      //End
      void end(void) {
        buff.append("    </a>\n");
      }
      
      //Once
      void once(const string href, const string cont) {
        ifnotempty(href) {
          buff.append("    <a href=\"");
          buff.append(href);
          buff.append("\">");
          buff.append(cont);
          buff.append("</a>\n");
          tagCount++;
        }
      }
      
      void once(const TagArgs* ta) {
        if(ta == NULL) throw NullAsArgumentException();
        
        //Tag:
        //<a id class href>content</a>
        buff += "    <a";
        if(ta->id != "") {
          buff.append(" id=\"");
          buff.append(ta->id);
          buff.append("\" ");
        }
        if(ta->classs != "") {
          buff.append(" class=\"");
          buff.append(ta->classs);
          buff.append("\" ");
        }
        if(ta->href != "") {
          buff.append(" href=\"");
          buff.append(ta->href);
          buff.append("\" ");
        }
        buff.append(" >");
        if(ta->content != "") {
          buff.append(ta->content);
        }
        buff.append("</a>\n");
        tagCount++;
      }
    } a;
    
    
    struct { //Paragraph (p)
      //As container
      //Start
      void begin(const TagArgs* ta) {
        ifnull(ta) throw NullAsArgumentException();
        buff.append("    <p");
        ifnotempty(ta->styles) {
          buff.append(" style=\"");
          buff.append(ta->styles);
          buff.append("\"");
        }
        ifnotempty(ta->classs) {
          buff.append(" class=\"");
          buff.append(ta->classs);
          buff.append("\"");
        }
        ifnotempty(ta->id) {
          buff.append(" id=\"");
          buff.append(ta->classs);
          buff.append("\"");
        }
        buff.append(">\n");
        tagCount++;
      }
      
      //End
      void end(void) {
        buff.append("    </p>\n");
      }
      
      //Once
      void once(const string cont) {
        ifnotempty(cont) {
          buff.append("    <p>");
          buff.append(cont);
          buff.append("</p>\n");
          tagCount++;
        }
      }
      
      void once(const TagArgs* ta) {
        //Tag:
        //<a id class href>content</a>
        buff.append("    <p");
        if(ta->id != "") {
          buff.append(" id=\"");
          buff.append(ta->id);
          buff.append("\" ");
        }
        if(ta->classs != "") {
          buff.append(" class=\"");
          buff.append(ta->classs);
          buff.append("\" ");
        }
        buff.append(" >");
        if(ta->content != "") {
          buff.append(ta->content);
        }
        buff.append("</p>\n");
        tagCount++;
      }
    } p;
  } Tag;
  
  void end(void) {
    buff.append(
      "  </body>\n"
      "</html>\n"
    );
  }
};