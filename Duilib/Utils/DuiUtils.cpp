#include "StdAfx.h"
#include "DuiUtils.h"

namespace DuiLib
{

    //////////////////////////////////////////////////////////////////////////////////////
    //
    char* w2a(wchar_t* lpszSrc)
    {
        if(lpszSrc != NULL)
        {
            int  nANSILen = WideCharToMultiByte(CP_ACP, 0, lpszSrc, -1, NULL, 0, NULL, NULL);
            char* pANSI = new char[nANSILen + 1];
            if(pANSI != NULL)
            {
                ZeroMemory(pANSI, nANSILen + 1);
                WideCharToMultiByte(CP_ACP, 0, lpszSrc, -1, pANSI, nANSILen, NULL, NULL);
                return pANSI;
            }
        }
        return NULL;
    }

    wchar_t* a2w(char* lpszSrc)
    {
        if(lpszSrc != NULL)
        {
            int nUnicodeLen = MultiByteToWideChar(CP_ACP, 0, lpszSrc, -1, NULL, 0);
            LPWSTR pUnicode = new WCHAR[nUnicodeLen + 1];
            if(pUnicode != NULL)
            {
                ZeroMemory((void*)pUnicode, (nUnicodeLen + 1) * sizeof(WCHAR));
                MultiByteToWideChar(CP_ACP, 0, lpszSrc, -1, pUnicode, nUnicodeLen);
                return pUnicode;
            }
        }
        return NULL;
    }
    //////////////////////////////////////////////////////////////////////////////////////
    //
    CDuiConsole::CDuiConsole(BOOL bOpen)
        : m_bOpen(bOpen)
    {
        if(m_bOpen)
        {
            AllocConsole();
            freopen("CONOUT$", "w+t", stdout);
            freopen("CONIN$", "r+t", stdin);
            setlocale(LC_ALL, "chs");
            TCHAR pszOldWindowTitle[1024];
            GetConsoleTitle(pszOldWindowTitle, sizeof(pszOldWindowTitle));
            SendMessage(FindWindow(NULL, pszOldWindowTitle), WM_SYSCOMMAND, SC_MINIMIZE, 0);
        }
    }

    CDuiConsole::~CDuiConsole()
    {
        if(m_bOpen)
        {
            FreeConsole();
        }
    }


    /////////////////////////////////////////////////////////////////////////////////////
    //
    //


    CDuiTimeInterval::CDuiTimeInterval()
    {
        m_dwMesc = GetTickCount();
    }


    CDuiTimeInterval::~CDuiTimeInterval()
    {
        DWORD dwRes = GetTickCount() - m_dwMesc;
        DUI_TRACE("[%d]ms", dwRes);
    }

    /////////////////////////////////////////////////////////////////////////////////////
    //
    //

    CIdToResource::CIdToResource(LPCTSTR lpString)
        : m_lpstr(lpString)
    {
    }


    CIdToResource::CIdToResource(UINT nID)
        : m_lpstr(MAKEINTRESOURCE(nID))
    {
    }

    /////////////////////////////////////////////////////////////////////////////////////
    //
    //

    CDuiPoint::CDuiPoint()
    {
        x = y = 0;
    }

    CDuiPoint::CDuiPoint(const POINT& src)
    {
        x = src.x;
        y = src.y;
    }

    CDuiPoint::CDuiPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    CDuiPoint::CDuiPoint(LPARAM lParam)
    {
        x = GET_X_LPARAM(lParam);
        y = GET_Y_LPARAM(lParam);
    }

    BOOL CDuiPoint::operator==(const POINT& point) const
    {
        return (x == point.x && y == point.y);
    }

    BOOL CDuiPoint::operator!=(const POINT& point) const
    {
        return (x != point.x || y != point.y);
    }

    void CDuiPoint::operator+=(const POINT& point)
    {
        x += point.x;
        y += point.y;
    }

    void CDuiPoint::operator-=(const POINT& point)
    {
        x -= point.x;
        y -= point.y;
    }

    /////////////////////////////////////////////////////////////////////////////////////
    //
    //

    CDuiSize::CDuiSize()
    {
        cx = cy = 0;
    }

    CDuiSize::CDuiSize(const SIZE& src)
    {
        cx = src.cx;
        cy = src.cy;
    }

    CDuiSize::CDuiSize(const RECT rc)
    {
        cx = rc.right - rc.left;
        cy = rc.bottom - rc.top;
    }

    CDuiSize::CDuiSize(const int _cx, const int _cy)
    {
        cx = _cx;
        cy = _cy;
    }

    BOOL CDuiSize::operator==(const SIZE& size) const
    {
        return (cx == size.cx && cy == size.cy);
    }

    BOOL CDuiSize::operator!=(const SIZE& size) const
    {
        return (cx != size.cx || cy != size.cy);
    }

    void CDuiSize::operator+=(const SIZE& size)
    {
        cx += size.cx;
        cy += size.cy;
    }

    void CDuiSize::operator-=(const SIZE& size)
    {
        cx -= size.cx;
        cy -= size.cy;
    }

    CDuiSize CDuiSize::operator+(const SIZE& size) const
    {
        return CDuiSize(cx + size.cx, cy + size.cy);
    }

    CDuiSize CDuiSize::operator-(const SIZE& size) const
    {
        return CDuiSize(cx - size.cx, cy - size.cy);
    }

    void CDuiSize::SetSize(const int CX, const int CY)
    {
        cx = CX;
        cy = CY;
    }
    /////////////////////////////////////////////////////////////////////////////////////
    //
    //

    CDuiRect::CDuiRect()
    {
        left = top = right = bottom = 0;
    }

    CDuiRect::CDuiRect(const RECT& src)
    {
        ::CopyRect(this, &src);
    }

    CDuiRect::CDuiRect(const LPCRECT lpSrcRect)
    {
        ::CopyRect(this, lpSrcRect);
    }

    CDuiRect::CDuiRect(int iLeft, int iTop, int iRight, int iBottom)
    {
        left = iLeft;
        top = iTop;
        right = iRight;
        bottom = iBottom;
    }

    BOOL CDuiRect::operator==(const RECT& rect) const
    {
        return ::EqualRect(this, &rect);
    }

    BOOL CDuiRect::operator!=(const RECT& rect) const
    {
        return !::EqualRect(this, &rect);
    }

    void CDuiRect::operator+=(const RECT& rect)
    {
        left -= rect.left;
        top -= rect.top;
        right += rect.right;
        bottom += rect.bottom;
    }

    void CDuiRect::operator-=(const RECT& rect)
    {
        left += rect.left;
        top += rect.top;
        right -= rect.right;
        bottom -= rect.bottom;
    }

    int CDuiRect::GetWidth() const
    {
        return right - left;
    }

    int CDuiRect::GetHeight() const
    {
        return bottom - top;
    }

    void CDuiRect::Empty()
    {
        left = top = right = bottom = 0;
    }

    BOOL CDuiRect::IsNull() const
    {
        return (left == 0 && right == 0 && top == 0 && bottom == 0);
    }

    void CDuiRect::Join(const RECT& rc)
    {
        if(rc.left < left)
        {
            left = rc.left;
        }
        if(rc.top < top)
        {
            top = rc.top;
        }
        if(rc.right > right)
        {
            right = rc.right;
        }
        if(rc.bottom > bottom)
        {
            bottom = rc.bottom;
        }
    }

    void CDuiRect::ResetOffset()
    {
        ::OffsetRect(this, -left, -top);
    }

    void CDuiRect::Normalize()
    {
        if(left > right)
        {
            int iTemp = left;
            left = right;
            right = iTemp;
        }
        if(top > bottom)
        {
            int iTemp = top;
            top = bottom;
            bottom = iTemp;
        }
    }

    void CDuiRect::Offset(int cx, int cy)
    {
        ::OffsetRect(this, cx, cy);
    }

    void CDuiRect::Inflate(int cx, int cy)
    {
        ::InflateRect(this, cx, cy);
    }

    void CDuiRect::Deflate(int cx, int cy)
    {
        ::InflateRect(this, -cx, -cy);
    }

    void CDuiRect::Union(CDuiRect& rc)
    {
        ::UnionRect(this, this, &rc);
    }

    CDuiRect CDuiRect::MulDiv(int nMultiplier, int nDivisor) const
    {
        return CDuiRect(::MulDiv(left, nMultiplier, nDivisor),
                        ::MulDiv(top, nMultiplier, nDivisor),
                        ::MulDiv(right, nMultiplier, nDivisor),
                        ::MulDiv(bottom, nMultiplier, nDivisor));
    }
    //////////////////////////////////////////////////////////////////////
    CDuiRectD::CDuiRectD()
        : left(0.0f)
        , top(0.0f)
        , right(0.0f)
        , bottom(0.0f)
    {

    }


    CDuiRectD::CDuiRectD(const CDuiRectD& src)
    {
        left = src.left;
        top = src.top;
        right = src.right;
        bottom = src.bottom;
    }

    //////////////////////////////////////////////////////////////////////
    CStdPtrArray::CStdPtrArray(int iPreallocSize)
        : m_ppData(NULL)
        , m_iCount(0)
        , m_iAllocated(iPreallocSize)
    {
        ASSERT(iPreallocSize >= 0);
        if(iPreallocSize > 0)
        {
            m_ppData = static_cast<LPVOID*>(malloc(iPreallocSize * sizeof(LPVOID)));
        }
    }

    CStdPtrArray::CStdPtrArray(const CStdPtrArray& src)
        : m_ppData(NULL)
        , m_iCount(0)
        , m_iAllocated(0)
    {
        for(int i = 0; i < src.GetSize(); i++)
        {
            Add(src.GetAt(i));
        }
    }

    CStdPtrArray::~CStdPtrArray()
    {
        if(m_ppData != NULL)
        {
            free(m_ppData);
            m_ppData = NULL;
        }
    }

    void CStdPtrArray::Empty()
    {
        if(m_ppData != NULL)
        {
            free(m_ppData);
            m_ppData = NULL;
        }
        m_ppData = NULL;
        m_iCount = m_iAllocated = 0;
    }

    void CStdPtrArray::Resize(int iSize)
    {
        Empty();
        m_ppData = static_cast<LPVOID*>(malloc(iSize * sizeof(LPVOID)));
        ::ZeroMemory(m_ppData, iSize * sizeof(LPVOID));
        m_iAllocated = iSize;
        m_iCount = iSize;
    }

    BOOL CStdPtrArray::IsEmpty() const
    {
        return m_iCount == 0;
    }

    BOOL CStdPtrArray::Add(LPVOID pData)
    {
        if(++m_iCount >= m_iAllocated)
        {
            int nAllocated = m_iAllocated * 2;
            if(nAllocated == 0)
            {
                nAllocated = 11;
            }
            LPVOID* ppVoid = static_cast<LPVOID*>(realloc(m_ppData, nAllocated * sizeof(LPVOID)));
            if(ppVoid != NULL)
            {
                m_iAllocated = nAllocated;
                m_ppData = ppVoid;
            }
            else
            {
                --m_iCount;
                return FALSE;
            }
        }
        m_ppData[m_iCount - 1] = pData;
        return TRUE;
    }

    BOOL CStdPtrArray::InsertAt(int iIndex, LPVOID pData)
    {
        if(iIndex == m_iCount)
        {
            return Add(pData);
        }
        if(iIndex < 0 || iIndex > m_iCount)
        {
            return FALSE;
        }
        if(++m_iCount >= m_iAllocated)
        {
            int nAllocated = m_iAllocated * 2;
            if(nAllocated == 0)
            {
                nAllocated = 11;
            }
            LPVOID* ppVoid = static_cast<LPVOID*>(realloc(m_ppData, nAllocated * sizeof(LPVOID)));
            if(ppVoid != NULL)
            {
                m_iAllocated = nAllocated;
                m_ppData = ppVoid;
            }
            else
            {
                --m_iCount;
                return FALSE;
            }
        }
        memmove(&m_ppData[iIndex + 1], &m_ppData[iIndex], (m_iCount - iIndex - 1) * sizeof(LPVOID));
        m_ppData[iIndex] = pData;
        return TRUE;
    }

    BOOL CStdPtrArray::SetAt(int iIndex, LPVOID pData)
    {
        if(iIndex < 0 || iIndex >= m_iCount)
        {
            return FALSE;
        }
        m_ppData[iIndex] = pData;
        return TRUE;
    }

    BOOL CStdPtrArray::Remove(int iIndex)
    {
        if(iIndex < 0 || iIndex >= m_iCount)
        {
            return FALSE;
        }
        if(iIndex < --m_iCount)
        {
            ::CopyMemory(m_ppData + iIndex, m_ppData + iIndex + 1, (m_iCount - iIndex) * sizeof(LPVOID));
        }
        return TRUE;
    }

    int CStdPtrArray::Find(LPVOID pData) const
    {
        for(int i = 0; i < m_iCount; i++)
        {
            if(m_ppData[i] == pData)
            {
                return i;
            }
        }
        return -1;
    }

    int CStdPtrArray::GetSize() const
    {
        return m_iCount;
    }

    LPVOID* CStdPtrArray::GetData()
    {
        return m_ppData;
    }

    LPVOID CStdPtrArray::GetAt(int iIndex) const
    {
        if(iIndex < 0 || iIndex >= m_iCount)
        {
            return NULL;
        }
        return m_ppData[iIndex];
    }

    LPVOID CStdPtrArray::operator[](int iIndex) const
    {
        ASSERT(iIndex >= 0 && iIndex < m_iCount);
        return m_ppData[iIndex];
    }

    /////////////////////////////////////////////////////////////////////////////
    //
    //

    static UINT HashKey(LPCTSTR Key)
    {
        UINT i = 0;
        SIZE_T len = _tcslen(Key);
        while(len-- > 0)
        {
            i = (i << 5) + i + Key[len];
        }
        return i;
    }

    static UINT HashKey(const CDuiString& Key)
    {
        return HashKey((LPCTSTR)Key);
    };

    CStdStringPtrMap::CStdStringPtrMap(int nSize) : m_nCount(0)
    {
        if(nSize < 16)
        {
            nSize = 16;
        }
        m_nBuckets = nSize;
        m_aT = new TITEM*[nSize];
        memset(m_aT, 0, nSize * sizeof(TITEM*));
    }

    CStdStringPtrMap::~CStdStringPtrMap()
    {
        if(m_aT)
        {
            int len = m_nBuckets;
            while(len--)
            {
                TITEM* pItem = m_aT[len];
                while(pItem)
                {
                    TITEM* pKill = pItem;
                    pItem = pItem->pNext;
                    DUI_FREE_POINT(pKill);
                }
            }
            DUI_FREE_ARRAY(m_aT);
        }
    }

    void CStdStringPtrMap::RemoveAll()
    {
        Resize(m_nBuckets);
    }

    void CStdStringPtrMap::Resize(int nSize)
    {
        if(m_aT)
        {
            int len = m_nBuckets;
            while(len--)
            {
                TITEM* pItem = m_aT[len];
                while(pItem)
                {
                    TITEM* pKill = pItem;
                    pItem = pItem->pNext;
                    DUI_FREE_POINT(pKill);
                }
            }
            DUI_FREE_ARRAY(m_aT);
        }
        if(nSize < 0)
        {
            nSize = 0;
        }
        if(nSize > 0)
        {
            m_aT = new TITEM*[nSize];
            memset(m_aT, 0, nSize * sizeof(TITEM*));
        }
        m_nBuckets = nSize;
        m_nCount = 0;
    }

    LPVOID CStdStringPtrMap::Find(LPCTSTR key, BOOL optimize) const
    {
        if(m_nBuckets == 0 || GetSize() == 0)
        {
            return NULL;
        }
        UINT slot = HashKey(key) % m_nBuckets;
        for(TITEM* pItem = m_aT[slot]; pItem; pItem = pItem->pNext)
        {
            if(pItem->Key == key)
            {
                if(optimize && pItem != m_aT[slot])
                {
                    if(pItem->pNext)
                    {
                        pItem->pNext->pPrev = pItem->pPrev;
                    }
                    pItem->pPrev->pNext = pItem->pNext;
                    pItem->pPrev = NULL;
                    pItem->pNext = m_aT[slot];
                    pItem->pNext->pPrev = pItem;
                    //将item移动至链条头部
                    m_aT[slot] = pItem;
                }
                return pItem->Data;
            }
        }
        return NULL;
    }

    BOOL CStdStringPtrMap::Insert(LPCTSTR key, LPVOID pData)
    {
        if(m_nBuckets == 0)
        {
            return FALSE;
        }
        if(Find(key))
        {
            return FALSE;
        }
        // Add first in bucket
        UINT slot = HashKey(key) % m_nBuckets;
        TITEM* pItem = new TITEM;
        pItem->Key = key;
        pItem->Data = pData;
        pItem->pPrev = NULL;
        pItem->pNext = m_aT[slot];
        if(pItem->pNext)
        {
            pItem->pNext->pPrev = pItem;
        }
        m_aT[slot] = pItem;
        m_nCount++;
        return TRUE;
    }

    LPVOID CStdStringPtrMap::Set(LPCTSTR key, LPVOID pData)
    {
        if(m_nBuckets == 0)
        {
            return pData;
        }
        if(GetSize() > 0)
        {
            UINT slot = HashKey(key) % m_nBuckets;
            // Modify existing item
            for(TITEM* pItem = m_aT[slot]; pItem; pItem = pItem->pNext)
            {
                if(pItem->Key == key)
                {
                    LPVOID pOldData = pItem->Data;
                    pItem->Data = pData;
                    return pOldData;
                }
            }
        }
        Insert(key, pData);
        return NULL;
    }

    BOOL CStdStringPtrMap::Remove(LPCTSTR key)
    {
        if(m_nBuckets == 0 || GetSize() == 0)
        {
            return FALSE;
        }
        UINT slot = HashKey(key) % m_nBuckets;
        TITEM** ppItem = &m_aT[slot];
        while(*ppItem)
        {
            if((*ppItem)->Key == key)
            {
                TITEM* pKill = *ppItem;
                *ppItem = (*ppItem)->pNext;
                if(*ppItem)
                {
                    (*ppItem)->pPrev = pKill->pPrev;
                }
                DUI_FREE_POINT(pKill);
                m_nCount--;
                return TRUE;
            }
            ppItem = &((*ppItem)->pNext);
        }
        return FALSE;
    }

    int CStdStringPtrMap::GetSize() const
    {
#if 0//def _DEBUG
        int nCount = 0;
        int len = m_nBuckets;
        while(len--)
        {
            for(const TITEM* pItem = m_aT[len]; pItem; pItem = pItem->pNext)
            {
                nCount++;
            }
        }
        ASSERT(m_nCount == nCount);
#endif
        return m_nCount;
    }

    LPCTSTR CStdStringPtrMap::GetAt(int iIndex) const
    {
        if(m_nBuckets == 0 || GetSize() == 0)
        {
            return FALSE;
        }
        int pos = 0;
        int len = m_nBuckets;
        while(len--)
        {
            for(TITEM* pItem = m_aT[len]; pItem; pItem = pItem->pNext)
            {
                if(pos++ == iIndex)
                {
                    return pItem->Key.GetData();
                }
            }
        }
        return NULL;
    }

    LPCTSTR CStdStringPtrMap::operator[](int nIndex) const
    {
        return GetAt(nIndex);
    }

}