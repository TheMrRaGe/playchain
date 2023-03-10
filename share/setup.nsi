Name "Playchain (64-bit)"

RequestExecutionLevel highest
SetCompressor /SOLID lzma
SetDateSave off
Unicode true

# Uncomment these lines when investigating reproducibility errors
#SetCompress off
#SetDatablockOptimize off

# General Symbol Definitions
!define REGKEY "SOFTWARE\$(^Name)"
!define COMPANY "Playchain project"
!define URL https://playchain.io/

# MUI Symbol Definitions
!define MUI_ICON "/mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/share/pixmaps/bitcoin.ico"
!define MUI_WELCOMEFINISHPAGE_BITMAP "/mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/share/pixmaps/nsis-wizard.bmp"
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_HEADERIMAGE_BITMAP "/mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/share/pixmaps/nsis-header.bmp"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_STARTMENUPAGE_REGISTRY_ROOT HKLM
!define MUI_STARTMENUPAGE_REGISTRY_KEY ${REGKEY}
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME StartMenuGroup
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "Playchain"
!define MUI_FINISHPAGE_RUN "$WINDIR\explorer.exe"
!define MUI_FINISHPAGE_RUN_PARAMETERS $INSTDIR\playchain-qt.exe
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "/mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/share/pixmaps/nsis-wizard.bmp"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE

# Included files
!include Sections.nsh
!include MUI2.nsh
!include x64.nsh

# Variables
Var StartMenuGroup

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_STARTMENU Application $StartMenuGroup
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
InstallDir $PROGRAMFILES64\Playchain
CRCCheck force
XPStyle on
BrandingText " "
ShowInstDetails show
VIProductVersion 1.8.0.0
VIAddVersionKey ProductName "Playchain"
VIAddVersionKey ProductVersion "1.8.99"
VIAddVersionKey CompanyName "${COMPANY}"
VIAddVersionKey CompanyWebsite "${URL}"
VIAddVersionKey FileVersion "1.8.99"
VIAddVersionKey FileDescription "Installer for Playchain"
VIAddVersionKey LegalCopyright "Copyright (C) 2009-2022 The Bitcoin Core, Namecoin and Playchain developers"
InstallDirRegKey HKCU "${REGKEY}" Path
ShowUninstDetails show

# Installer sections
Section -Main SEC0000
    SetOutPath $INSTDIR
    SetOverwrite on
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/release/playchain-qt.exe
    File /oname=COPYING.txt /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/COPYING
    File /oname=readme.txt /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/doc/README_windows.txt
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/share/examples/bitcoin.conf
    SetOutPath $INSTDIR\share\rpcauth
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/share/rpcauth/*.*
    SetOutPath $INSTDIR\daemon
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/release/playchaind.exe
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/release/playchain-cli.exe
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/release/playchain-tx.exe
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/release/playchain-wallet.exe
    File /mnt/c/Users/Shwif/OneDrive/Desktop/GamingChain/playchain/release/test_playchain.exe
    SetOutPath $INSTDIR
    WriteRegStr HKCU "${REGKEY}\Components" Main 1
SectionEnd

Section -post SEC0001
    WriteRegStr HKCU "${REGKEY}" Path $INSTDIR
    SetOutPath $INSTDIR
    WriteUninstaller $INSTDIR\uninstall.exe
    !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
    CreateDirectory $SMPROGRAMS\$StartMenuGroup
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\$(^Name).lnk" $INSTDIR\playchain-qt.exe
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\Playchain (testnet, 64-bit).lnk" "$INSTDIR\playchain-qt.exe" "-testnet" "$INSTDIR\playchain-qt.exe" 1
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\Uninstall $(^Name).lnk" $INSTDIR\uninstall.exe
    !insertmacro MUI_STARTMENU_WRITE_END
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayName "$(^Name)"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayVersion "1.8.99"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" Publisher "${COMPANY}"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" URLInfoAbout "${URL}"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayIcon $INSTDIR\playchain-qt.exe
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" UninstallString $INSTDIR\uninstall.exe
    WriteRegDWORD HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoModify 1
    WriteRegDWORD HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoRepair 1
    WriteRegStr HKCR "playchain" "URL Protocol" ""
    WriteRegStr HKCR "playchain" "" "URL:Playchain"
    WriteRegStr HKCR "playchain\DefaultIcon" "" $INSTDIR\playchain-qt.exe
    WriteRegStr HKCR "playchain\shell\open\command" "" '"$INSTDIR\playchain-qt.exe" "%1"'
SectionEnd

# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKCU "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
next${UNSECTION_ID}:
    !insertmacro UnselectSection "${UNSECTION_ID}"
done${UNSECTION_ID}:
    Pop $R0
!macroend

# Uninstaller sections
Section /o -un.Main UNSEC0000
    Delete /REBOOTOK $INSTDIR\playchain-qt.exe
    Delete /REBOOTOK $INSTDIR\COPYING.txt
    Delete /REBOOTOK $INSTDIR\readme.txt
    Delete /REBOOTOK $INSTDIR\bitcoin.conf
    RMDir /r /REBOOTOK $INSTDIR\share
    RMDir /r /REBOOTOK $INSTDIR\daemon
    DeleteRegValue HKCU "${REGKEY}\Components" Main
SectionEnd

Section -un.post UNSEC0001
    DeleteRegKey HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\Uninstall $(^Name).lnk"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\$(^Name).lnk"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\Playchain (testnet, 64-bit).lnk"
    Delete /REBOOTOK "$SMSTARTUP\Playchain.lnk"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    Delete /REBOOTOK $INSTDIR\debug.log
    Delete /REBOOTOK $INSTDIR\db.log
    DeleteRegValue HKCU "${REGKEY}" StartMenuGroup
    DeleteRegValue HKCU "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKCU "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKCU "${REGKEY}"
    DeleteRegKey HKCR "playchain"
    RmDir /REBOOTOK $SMPROGRAMS\$StartMenuGroup
    RmDir /REBOOTOK $INSTDIR
    Push $R0
    StrCpy $R0 $StartMenuGroup 1
    StrCmp $R0 ">" no_smgroup
no_smgroup:
    Pop $R0
SectionEnd

# Installer functions
Function .onInit
    InitPluginsDir
    ${If} ${RunningX64}
      ; disable registry redirection (enable access to 64-bit portion of registry)
      SetRegView 64
    ${Else}
      MessageBox MB_OK|MB_ICONSTOP "Cannot install 64-bit version on a 32-bit system."
      Abort
    ${EndIf}
FunctionEnd

# Uninstaller functions
Function un.onInit
    ReadRegStr $INSTDIR HKCU "${REGKEY}" Path
    !insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuGroup
    !insertmacro SELECT_UNSECTION Main ${UNSEC0000}
FunctionEnd
