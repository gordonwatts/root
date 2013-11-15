Here is what I needed to do to update vc12:

1) Use CMake to generate a vc12 project
2) Open it up, and edit the CMakeLists.txt associated with Cint_static
3) Add a VC_MAJOR EQUAL 18 line, set it to fakstrm.cxx
4) Build cint.exe
5) Copy the vc12\bin\Debug directory into vc12\bin\DebugFake
  This is a special version of cint that, basically, does not use iostream linkages.
6) in powershell, cd into this directory
7) Run the powershell script.
  I had to modify sstrm.h to remove the #Include <string> line...
8) Once it runs, then go back into the CMakeLists.txt, and replace fakstrm with vc12strm
9) To get it to build I had to remove a reference to the void* operator in basic_ios.
10) Once that builds, in the vc12strm.cxx class, remove the following lines (at the very end):

class G__cpp_setup_initG__stream {
  public:
    G__cpp_setup_initG__stream() { G__add_setup_func("G__stream",(G__incsetup)(&G__cpp_setupG__stream)); G__call_setup_funcs(); }
   ~G__cpp_setup_initG__stream() { G__remove_setup_func("G__stream"); }
};
G__cpp_setup_initG__stream G__cpp_setup_initializerG__stream;

**** Old instructions and information.


lib/iccstrm/README

lib/iccstrm directory exists for creating iostream library linkage file
src/iccstrm.cxx and src/iccstrm.h for Intel icc (IA-32) and ecc (IA-64)
compilers. These files contain interface methods for iostream library. 
You can create those by doing 'make' under this directory. Usually nobody
but only author should do this. User doesn't need to recognize this.
Files in this directory are originally copied from lib/gcc3strm/* and 
modified for iccstrm.

 cbstream.cpp is based on template based stream library.

 Creating src/iccstrm.cxx

 1) Just do 'make' in this directory. 
  I think we can forget all below because of new new/delete scheme.

 ...................................................................

 1) Edit src/newlink.c
  Start a text editor, look for '#define G__N_EXPLICITDESTRUCTOR'. Please
  comment this line out. 

 2) Create special 'cint'
  Go back to $CINTSYSDIR and do make to create special 'cint'. You may need
  to specify src/fakestrm.cxx in src/Makefile.

 3) Come to src/snstream directory and do make to create src/snstrm.cxx.

 4) Edit src/newlink.c
  Edit src/newlink.c and restore '#define G__N_EXPLICITDESTRUCTOR' macro.

 5) Go back to $CINTSYSDIR and do make to create updated cint.
