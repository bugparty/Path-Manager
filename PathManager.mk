##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PathManager
ConfigurationName      :=Debug
WorkspacePath          := "D:\wins\PathManager"
ProjectPath            := "D:\wins\PathManager"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=博文
Date                   :=2014/12/18
CodeLitePath           :="D:\Program Files\CodeLite"
LinkerName             :=C:/TDM-GCC-32/bin/g++.exe 
SharedObjectLinkerName :=C:/TDM-GCC-32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g -fexec-charset=GBK -finput-charset=UTF-8
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c -fexec-charset=GBK -finput-charset=UTF-8
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PathManager.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-32/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)gdi32 $(LibrarySwitch)user32 $(LibrarySwitch)kernel32 $(LibrarySwitch)comctl32 $(LibrarySwitch)comdlg32 
ArLibs                 :=  "gdi32" "user32" "kernel32" "comctl32" "comdlg32" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-32/bin/ar.exe rcu
CXX      := C:/TDM-GCC-32/bin/g++.exe 
CC       := C:/TDM-GCC-32/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-32/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=d:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_actions.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_dialogs.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_util.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_stdafx.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_document.cpp$(ObjectSuffix) $(IntermediateDirectory)/res_resource.rc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:

# PreCompiled Header
D:/wins/PathManager/include/stdafx.h.gch: D:/wins/PathManager/include/stdafx.h
	$(CXX) $(SourceSwitch) D:/wins/PathManager/include/stdafx.h $(PCHCompileFlags)



##
## Objects
##
$(IntermediateDirectory)/src_actions.cpp$(ObjectSuffix): src/actions.cpp $(IntermediateDirectory)/src_actions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/wins/PathManager/src/actions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_actions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_actions.cpp$(DependSuffix): src/actions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_actions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_actions.cpp$(DependSuffix) -MM "src/actions.cpp"

$(IntermediateDirectory)/src_actions.cpp$(PreprocessSuffix): src/actions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_actions.cpp$(PreprocessSuffix) "src/actions.cpp"

$(IntermediateDirectory)/src_dialogs.cpp$(ObjectSuffix): src/dialogs.cpp $(IntermediateDirectory)/src_dialogs.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/wins/PathManager/src/dialogs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_dialogs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_dialogs.cpp$(DependSuffix): src/dialogs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_dialogs.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_dialogs.cpp$(DependSuffix) -MM "src/dialogs.cpp"

$(IntermediateDirectory)/src_dialogs.cpp$(PreprocessSuffix): src/dialogs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_dialogs.cpp$(PreprocessSuffix) "src/dialogs.cpp"

$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp $(IntermediateDirectory)/src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/wins/PathManager/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(DependSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM "src/main.cpp"

$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) "src/main.cpp"

$(IntermediateDirectory)/src_util.cpp$(ObjectSuffix): src/util.cpp $(IntermediateDirectory)/src_util.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/wins/PathManager/src/util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_util.cpp$(DependSuffix): src/util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_util.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_util.cpp$(DependSuffix) -MM "src/util.cpp"

$(IntermediateDirectory)/src_util.cpp$(PreprocessSuffix): src/util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_util.cpp$(PreprocessSuffix) "src/util.cpp"

$(IntermediateDirectory)/src_stdafx.cpp$(ObjectSuffix): src/stdafx.cpp $(IntermediateDirectory)/src_stdafx.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/wins/PathManager/src/stdafx.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_stdafx.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_stdafx.cpp$(DependSuffix): src/stdafx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_stdafx.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_stdafx.cpp$(DependSuffix) -MM "src/stdafx.cpp"

$(IntermediateDirectory)/src_stdafx.cpp$(PreprocessSuffix): src/stdafx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_stdafx.cpp$(PreprocessSuffix) "src/stdafx.cpp"

$(IntermediateDirectory)/src_document.cpp$(ObjectSuffix): src/document.cpp $(IntermediateDirectory)/src_document.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/wins/PathManager/src/document.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_document.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_document.cpp$(DependSuffix): src/document.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_document.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_document.cpp$(DependSuffix) -MM "src/document.cpp"

$(IntermediateDirectory)/src_document.cpp$(PreprocessSuffix): src/document.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_document.cpp$(PreprocessSuffix) "src/document.cpp"

$(IntermediateDirectory)/res_resource.rc$(ObjectSuffix): res/resource.rc
	$(RcCompilerName) -i "D:/wins/PathManager/res/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/res_resource.rc$(ObjectSuffix) $(RcIncludePath)

-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/PathManager"
	$(RM) D:/wins/PathManager/include/stdafx.h.gch


