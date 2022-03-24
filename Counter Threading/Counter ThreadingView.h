
// Counter ThreadingView.h : interface of the CCounterThreadingView class
//

#pragma once


class CCounterThreadingView : public CView
{
protected: // create from serialization only
	CCounterThreadingView() noexcept;
	DECLARE_DYNCREATE(CCounterThreadingView)
	CWinThread* pThread;
// Attributes
public:
	CCounterThreadingDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCounterThreadingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	long m_iCounter;
	int x, y, angle, a, b, p, q ,c,d ;
	float t;
	afx_msg void OnControlsPause();
	afx_msg void OnControlsResume();
	afx_msg void OnControlsStart();
	afx_msg void OnControlsStartcycle();
};

#ifndef _DEBUG  // debug version in Counter ThreadingView.cpp
inline CCounterThreadingDoc* CCounterThreadingView::GetDocument() const
   { return reinterpret_cast<CCounterThreadingDoc*>(m_pDocument); }
#endif

