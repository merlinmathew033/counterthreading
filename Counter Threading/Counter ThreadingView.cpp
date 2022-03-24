
// Counter ThreadingView.cpp : implementation of the CCounterThreadingView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Counter Threading.h"
#endif
#include "Counter ThreadingDoc.h"
#include "Counter ThreadingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CCounterThreadingView

IMPLEMENT_DYNCREATE(CCounterThreadingView, CView)

BEGIN_MESSAGE_MAP(CCounterThreadingView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCounterThreadingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CONTROLS_PAUSE, &CCounterThreadingView::OnControlsPause)
	ON_COMMAND(ID_CONTROLS_RESUME, &CCounterThreadingView::OnControlsResume)
	ON_COMMAND(ID_CONTROLS_START, &CCounterThreadingView::OnControlsStart)
	ON_COMMAND(ID_CONTROLS_STARTCYCLE, &CCounterThreadingView::OnControlsStartcycle)
END_MESSAGE_MAP()

// CCounterThreadingView construction/destruction
CCounterThreadingView::CCounterThreadingView() noexcept

{
m_iCounter = 0;
angle = 0, a = 200, b = 190, p = 296, q = 240 ,c=392, d=290;
t = 3.14 / 180.0;
x = 350, y = 350;
}
CCounterThreadingView::~CCounterThreadingView()
{
}

BOOL CCounterThreadingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}
// CCounterThreadingView drawing
void CCounterThreadingView::OnDraw(CDC* pDC)
{
CCounterThreadingDoc* pDoc = GetDocument();
ASSERT_VALID(pDoc);
m_iCounter++;
CString strCounter;
strCounter.Format(L"The Counter is %d", m_iCounter);
pDC->TextOut(700, 100, strCounter);

// first planet
CPen greenpen;
greenpen.CreatePen(PS_SOLID, 5, RGB(0, 100, 0));
CPen* pOldpen1 = pDC->SelectObject(&greenpen);
pDC->Ellipse(-90, 20, 700, 600);
pDC->SelectObject(pOldpen1);


// second planet
CPen bluepen;
bluepen.CreatePen(PS_SOLID, 5, RGB(0, 0, 225));
CPen* pOldpen2 = pDC->SelectObject(&bluepen);
pDC->Ellipse(10, 70, 600, 550);
pDC->SelectObject(pOldpen2);

//third planet
CPen redpen;
redpen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
CPen* pOldpen = pDC->SelectObject(&redpen);
pDC->Ellipse(100, 120, 500, 500);
pDC->SelectObject(pOldpen);

//sun in red color
CBrush brushorange(RGB(255, 69, 0));
CBrush* pOldBrush = pDC->SelectObject(&brushorange);
pDC->Ellipse(250, 250, 350, 350);
pDC->SelectObject(pOldBrush);

// smallest orbit rotation
for (int i = 0; i < m_iCounter; i++)
{
angle = i;
x = a * cos(t*angle);
y = b  *sin(t*angle);
}
for (int i = 0; i < m_iCounter; i++)
{
CBrush brushblue(RGB(0, 0, 255));
CBrush* pOldBrush = pDC->SelectObject(&brushblue);
pDC->Ellipse(300 + x + 15, 310 + y + 20, 300 + x - 20, 310 + y - 20);

Invalidate();
pDC->SelectObject(pOldBrush);
}

// first orbit rotation
for (int i = 0; i < m_iCounter; i++)
{
	angle = i;
	x = c * cos(t * angle);

	y = d* sin(t * angle);

}
for (int i = 0; i < m_iCounter; i++)
{
	CBrush brushblack(RGB(0, 0, 0));
	CBrush* pOldBrush = pDC->SelectObject(&brushblack);
	pDC->Ellipse(310 + x + 25, 310 + y + 20, 310 + x - 20, 310 + y - 20);
	Invalidate();
	pDC->SelectObject(pOldBrush);
}

// second orbit rotation
for (int i = 0; i < m_iCounter; i++)
{
angle = i;
x = p*cos(t*angle);

y = q*sin(t*angle);

}
for (int i = 0; i < m_iCounter; i++)
{
CBrush brushblack(RGB(0, 0, 0));
CBrush* pOldBrush = pDC->SelectObject(&brushblack);
pDC->Ellipse(305 + x + 20, 310 + y + 20, 305 + x - 20, 310 + y - 20);
Invalidate();
pDC->SelectObject(pOldBrush);
}
}
// CCounterThreadingView printing
void CCounterThreadingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}
BOOL CCounterThreadingView::OnPreparePrinting(CPrintInfo* pInfo)
{
// default preparation
	return DoPreparePrinting(pInfo);
}
void CCounterThreadingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
// TODO: add extra initialization before printing
}

void CCounterThreadingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCounterThreadingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCounterThreadingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}
// CCounterThreadingView diagnostics

#ifdef _DEBUG
void CCounterThreadingView::AssertValid() const
{
	CView::AssertValid();
}

void CCounterThreadingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCounterThreadingDoc* CCounterThreadingView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCounterThreadingDoc)));
	return (CCounterThreadingDoc*)m_pDocument;
}
#endif //_DEBUG

 void CCounterThreadingView::OnControlsPause()

{
	pThread->SuspendThread();
}
void CCounterThreadingView::OnControlsResume()

{
	pThread->SuspendThread();
}
void CCounterThreadingView::OnControlsStart()
{
	pThread->SuspendThread();
}
void CCounterThreadingView::OnControlsStartcycle()
{
	pThread->SuspendThread();
}
