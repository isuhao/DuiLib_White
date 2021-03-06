
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef _SECURE_ATL
    #define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
    #define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"
#include "resource.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类
#include <atlsafe.h>



#ifndef _AFX_NO_OLE_SUPPORT
    #include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
    #include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持




#include "..\..\DuiLib\DuiLib.h"

using namespace DuiLib;

#ifdef _WIN64
    #ifdef _DEBUG
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64_d.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64A_d.lib")
        #endif
    #else
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibx64A.lib")
        #endif
    #endif
#else
    #ifdef _DEBUG
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLib_d.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibA_d.lib")
        #endif
    #else
        #ifdef _UNICODE
            #pragma comment(lib, "..\\..\\Lib\\DuiLib.lib")
        #else
            #pragma comment(lib, "..\\..\\Lib\\DuiLibA.lib")
        #endif
    #endif
#endif

#import "../../bin/msado15.dll" rename("EOF", "EndOfFile")
using namespace ADODB;

#include "mso9.tlh"
#include "VBE6EXT.tlh"
#include "excel9.tlh"

#ifdef _UNICODE
    #if defined _M_IX86
        #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
    #elif defined _M_X64
        #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
    #else
        #pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
    #endif
#endif


