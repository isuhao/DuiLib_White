#pragma once
namespace DuiLib
{
    class DUILIB_API CDuiCheckBox :
        public CDuiOption
    {
        DECLARE_DUICONTROL(CDuiOption)
    public:
        CDuiCheckBox(void);
        virtual ~CDuiCheckBox(void);
    public:
        CDuiString GetClass() const OVERRIDE;
        LPVOID GetInterface(CDuiString strName) OVERRIDE;

        BOOL IsAutoCheck() const;
        void SetAutoCheck(BOOL bEnable);

        BOOL GetCheck() const;
        void SetCheck(BOOL bCheck);

        void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue) OVERRIDE;
        void DoEvent(CDuiEvent& event) OVERRIDE;
    private:
        BOOL m_bAutoCheck;
    };

}