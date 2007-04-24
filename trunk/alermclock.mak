# Microsoft Developer Studio Generated NMAKE File, Based on alermclock.dsp
!IF "$(CFG)" == ""
CFG=alermclock - Win32 Debug
!MESSAGE No configuration specified. Defaulting to alermclock - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "alermclock - Win32 Release" && "$(CFG)" != "alermclock - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "alermclock.mak" CFG="alermclock - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "alermclock - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "alermclock - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "alermclock - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\alermclock.exe"


CLEAN :
	-@erase "$(INTDIR)\alermclock.obj"
	-@erase "$(INTDIR)\alermclock.pch"
	-@erase "$(INTDIR)\alermclock.res"
	-@erase "$(INTDIR)\alermclockDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\alermclock.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\alermclock.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\alermclock.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\alermclock.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\alermclock.pdb" /machine:I386 /out:"$(OUTDIR)\alermclock.exe" 
LINK32_OBJS= \
	"$(INTDIR)\alermclock.obj" \
	"$(INTDIR)\alermclockDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\alermclock.res"

"$(OUTDIR)\alermclock.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "alermclock - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\alermclock.exe" "$(OUTDIR)\alermclock.bsc"


CLEAN :
	-@erase "$(INTDIR)\alermclock.obj"
	-@erase "$(INTDIR)\alermclock.pch"
	-@erase "$(INTDIR)\alermclock.res"
	-@erase "$(INTDIR)\alermclock.sbr"
	-@erase "$(INTDIR)\alermclockDlg.obj"
	-@erase "$(INTDIR)\alermclockDlg.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\alermclock.bsc"
	-@erase "$(OUTDIR)\alermclock.exe"
	-@erase "$(OUTDIR)\alermclock.ilk"
	-@erase "$(OUTDIR)\alermclock.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\alermclock.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\alermclock.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\alermclock.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\alermclock.sbr" \
	"$(INTDIR)\alermclockDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\alermclock.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=D:\Softwares\Microsoft Visual Studio\VC98\Lib\SHELL32.LIB /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\alermclock.pdb" /debug /machine:I386 /out:"$(OUTDIR)\alermclock.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\alermclock.obj" \
	"$(INTDIR)\alermclockDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\alermclock.res"

"$(OUTDIR)\alermclock.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("alermclock.dep")
!INCLUDE "alermclock.dep"
!ELSE 
!MESSAGE Warning: cannot find "alermclock.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "alermclock - Win32 Release" || "$(CFG)" == "alermclock - Win32 Debug"
SOURCE=.\alermclock.cpp

!IF  "$(CFG)" == "alermclock - Win32 Release"


"$(INTDIR)\alermclock.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\alermclock.pch"


!ELSEIF  "$(CFG)" == "alermclock - Win32 Debug"


"$(INTDIR)\alermclock.obj"	"$(INTDIR)\alermclock.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\alermclock.pch"


!ENDIF 

SOURCE=.\alermclock.rc

"$(INTDIR)\alermclock.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\alermclockDlg.cpp

!IF  "$(CFG)" == "alermclock - Win32 Release"


"$(INTDIR)\alermclockDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\alermclock.pch"


!ELSEIF  "$(CFG)" == "alermclock - Win32 Debug"


"$(INTDIR)\alermclockDlg.obj"	"$(INTDIR)\alermclockDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\alermclock.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "alermclock - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\alermclock.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\alermclock.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "alermclock - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\alermclock.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\alermclock.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

