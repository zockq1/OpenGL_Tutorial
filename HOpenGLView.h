﻿
// HOpenGLView.h: CHOpenGLView 클래스의 인터페이스
//

#pragma once
#include <gl\gl.H>
#include <gl\glu.H>
//#include <gl\glut.h>
#include <gl\glaux.H>

#include "B711205.h"

#pragma comment(lib, "OPENGL32.LIB")
#pragma comment(lib, "GLAUX.LIB")
#pragma comment(lib, "GLU32.LIB")
#pragma comment(lib, "GLUT32.LIB")

class CHOpenGLView : public CView
{
protected: // serialization에서만 만들어집니다.
	CHOpenGLView() noexcept;
	DECLARE_DYNCREATE(CHOpenGLView)

// 특성입니다.
public:
	CHOpenGLDoc* GetDocument() const;

// 작업입니다.
public:
	HDC	m_hDC;
	HGLRC m_hglRC;
	B711205 m_B70011205;

	BOOL SetDevicePixelFormat(HDC hdc);
	void InitGL(void);
	void ReSizeGLScene(GLsizei width, GLsizei height);
	void DrawGLScene(void);
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CHOpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // HOpenGLView.cpp의 디버그 버전
inline CHOpenGLDoc* CHOpenGLView::GetDocument() const
   { return reinterpret_cast<CHOpenGLDoc*>(m_pDocument); }
#endif

