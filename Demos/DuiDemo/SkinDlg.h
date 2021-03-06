#pragma once

#include "DemoFrame.h"
class CSkinDlg
    : public CDuiDlgImplBase
{
    DUI_DECLARE_MESSAGE_MAP()
public:
    CSkinDlg(CDemoFrame* pDemoFrame);
    virtual ~CSkinDlg(void);
public:
    void InitWindow() OVERRIDE;
    CDuiString GetSkinFile() OVERRIDE;
    LPCTSTR GetWindowClassName() const OVERRIDE;
    void OnClick(CDuiNotify& msg);
    void OnSelectChanged(CDuiNotify& msg);
private:
    CDemoFrame* m_pDemoFrame;
    CDuiAnimationTabLayout* m_pTabSwitch ;
};

