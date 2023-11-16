#pragma once
/*
  FengYe - CPPML Rewrite Project
  Tuesday, Nov 14, 2023 by mxjeonsg
  
  Erroring.hpp $ Error handling classes
*/


enum FIO_FAULT {
  FIO_READ_GEN,
  FIO_READ_NOTREADE,
  FIO_WRITE_GEN,
  FIO_WRITE_NOTWRITTENE,
  FIO_UNSPEC
};

class FileNotFoundException {
  public:
  FileNotFoundException(string fname) {
    std::cerr <<
    "<[ERROR]>:\n" <<
    "Exception: FileNotFoundException(\"" << fname << "\");\n\n" <<
    "Description: Tried to open a file that doesn't exists.\n" <<
    "Requested File: `" << fname << "`\n\n" <<
    "Solutions: \n" <<
    "\t(•) Create the file.\n" <<
    "\t(•) Check file path in line.\n" <<
    "\t(•) I dunno man\n\n" <<
    "State: Irrecoverable\n" <<
    "Action: Abort (abort(3);)\n";
    
    abort();
  }
  
  FileNotFoundException(u8 ffd) {
    std::cerr <<
    "<[ERROR]>:\n" <<
    "Exception: FileNotFoundException(\"" << ffd << "\");\n\n" <<
    "Description: Tried to open a file that doesn't exists.\n" <<
    "Requested File Descriptor: `" << ffd << "`\n\n" <<
    "Solutions: \n" <<
    "\t(•) Create the file.\n" <<
    "\t(•) Check file path in line.\n" <<
    "\t(•) I dunno man\n\n" <<
    "State: Irrecoverable\n" <<
    "Action: Abort (abort(3);)\n";
    
    abort();
  }
};


class NullAsArgumentException {
  public:
  NullAsArgumentException(void) {
    std::cerr <<
    "<[ERROR]>:\n" <<
    "Exception: NullAsArgumentException();\n\n" <<
    "Description: Tried to use `NULL` as argument in a function that don't allow it.\n" <<
    "Solutions: \n" <<
    "\t(•) Call the function correctly.\n" <<
    "\t(•) Read function documentation.\n" <<
    "\t(•) ¯⁠\\⁠_⁠(⁠ツ⁠)⁠_⁠/⁠¯\n\n" <<
    "State: Recoverable\n" <<
    "Action: Skip function call (if(arg != NULL) {} else throw NullAsArgumentException(...);)\n";
  }
};


class EmptyArgumentException {
  public:
  EmptyArgumentException(void) {
    std::cerr <<
    "<[ERROR]>:\n" <<
    "Exception: EmptyArgumentException();\n\n" <<
    "Description: Tried to use `nothing` as argument in a function that don't allow it.\n" <<
    "Solutions: \n" <<
    "\t(•) Call the function correctly.\n" <<
    "\t(•) Read function documentation.\n" <<
    "\t(•) gg\n\n" <<
    "State: Irrecoverable\n" <<
    "Action: Abort (abort(3);)\n";
  }
};


class IOFaultException {
  public:
  IOFaultException(enum FIO_FAULT flt) {
    switch(flt) {
      case FIO_READ_GEN: {
        std::cerr <<
        "<[ERROR]>:\n" <<
        "Exception: IOFaultException(FIO_READ_GEN);\n\n" <<
        "Description: Read operation failed.\n" <<
        "Solutions: \n" <<
        "\t(•) Check if file isn't in use.\n" <<
        "\t(•) Check file permissions.\n" <<
        "\t(•) lol\n\n" <<
        "State: Irrecoverable\n" <<
        "Action: Abort (abort(3);)";
        
        abort();
      } break;
      
      case FIO_WRITE_GEN: {
        std::cerr <<
        "<[ERROR]>:\n" <<
        "Exception: IOFaultException(FIO_WRITE_GEN);\n\n" <<
        "Description: Write operation failed.\n" <<
        "Solutions: \n" <<
        "\t(•) Check if file isn't in use.\n" <<
        "\t(•) Check file permissions.\n" <<
        "\t(•) lol\n\n" <<
        "State: Irrecoverable\n" <<
        "Action: Abort (abort(3);)";
        
        abort();
      } break;
      
      case FIO_READ_NOTREADE: {
        std::cerr <<
        "<[ERROR]>:\n" <<
        "Exception: IOFaultException(FIO_READ_NOTREADE);\n\n" <<
        "Description: Read operation failed, function didn't read expected quantity of bytes.\n" <<
        "Solutions: \n" <<
        "\t(•) Check if file isn't in use.\n" <<
        "\t(•) Check file permissions.\n" <<
        "\t(•) lol\n\n" <<
        "State: Irrecoverable\n" <<
        "Action: Abort (abort(3);)";
        
        abort();
      } break;
      
      case FIO_WRITE_NOTWRITTENE: {
        std::cerr <<
        "<[ERROR]>:\n" <<
        "Exception: IOFaultException(FIO_WRITE_NOTWRITTENE);\n\n" <<
        "Description: Write operation failed, function didn't wrote expected quantity of bytes.\n" <<
        "Solutions: \n" <<
        "\t(•) Check if file isn't in use.\n" <<
        "\t(•) Check file permissions.\n" <<
        "\t(•) lol\n\n" <<
        "State: Irrecoverable\n" <<
        "Action: Abort (abort(3);)";
        
        abort();
      } break;
      
      default: abort();
    }
  }
};