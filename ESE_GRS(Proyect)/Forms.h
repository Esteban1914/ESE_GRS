#pragma once
#include "CRD.h"
#include "ESE_GRS.h"
enum Type
{
	ANIMACION,FORMS,BUTTON,BUTTONACEPTRB,BUTTONCANCELRB,BUTTONINITSETANGULES,BUTTONCANCELSETANGULES,TEXTBOX,LABEL,RADIOBUTTONGROUP,RADIOBUTTON,BOX
};
enum INTERFZType{
	ACEPT,CANCEL,SPECIFIC
};
class Forms
{
public:
	
	Type t;
	char*name;
	CRD*coord;
	float Wigth,Height,TotalWigth,TotalHeight;
	bool active,NoDraw;
	bool destruir;
	bool Cancel;
	bool reshapeBool;

public:
	Forms(){
		t=Type::FORMS;
		coord=new CRD();
		name=new char;
		active=NoDraw=destruir=Cancel=reshapeBool=false;
	};
	Forms(char*name,CRD coord,float wigth,float height,float TotalWigth,float TotalHeight){
		this->name=new char[strlen(name)+1];
		this->name[strlen(name)]=0;
		for(unsigned i=0;i<strlen(name);i++)
			this->name[i]=name[i];
		this->TotalHeight=TotalHeight;
		this->TotalWigth=TotalWigth;
		this->Wigth=wigth;
		this->Height=height;
		this->coord=new CRD(coord);
		this->active=true;
		this->NoDraw=false;
		destruir=Cancel=reshapeBool=false;
	};
	virtual ~Forms(){};
	static void Cancelar(Forms*f){f->Cancel=true;};
	static void Destruir(Forms*f){f->destruir=true;};
	static void SetName(char*name,Forms*f)
	{
		f->name=new char[strlen(name)+1];
		f->name[strlen(name)]=0;
		for(unsigned i=0;i<strlen(name);i++)
			f->name[i]=name[i];
	}
	static void SetCRD(CRD*coord,Forms*f){
		f->coord=new CRD(*coord);
	}
	static CRD*GetCoord(Forms*f){return f->coord;};
	virtual void ActivateDesactivate(bool ActDesact){
		this->active=ActDesact;
	};
	bool GetActiveDesavt(){return active;};
	virtual float LetterWigth(){return Wigth;}
	static void teXt(char*c,GLfloat x,GLfloat y,GLfloat R,GLfloat G,GLfloat B,unsigned LetterSize,Forms*f){
	//dibujo el char c en la posicion x,y,z con color RGB
	
	glColor3f(R,G,B);
	glRasterPos3f((GLfloat)-f->TotalWigth/2+x,(GLfloat)((f->TotalHeight/2)-y-f->Height*4/5),(GLfloat)2*f->TotalWigth-1);
	for(unsigned int i=0;i<strlen(c);i++){
		if(LetterSize==2)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
		else if(LetterSize==1)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
		else if(LetterSize==0)
	 	    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c[i]);
		
	}
}
	static bool IsPulsdo(float x,float y,Forms*f){
		if(x>=f->coord->x&&x<=f->coord->x+f->Wigth&&y>=f->coord->y&&y<=f->coord->y+f->Height)			
			return true;
		return false;
	}
	static void SetDraw(bool noDraw,Forms*f){
		f->NoDraw=noDraw;
	}
	virtual void NewTotalProp(float wigth,float height){
		if(reshapeBool)
			{
				this->coord->x=(this->coord->x*wigth)/this->TotalWigth;
		        this->coord->y=(this->coord->y*height)/this->TotalHeight;
		    }
		this->TotalWigth=wigth;
		this->TotalHeight=height;
	}
	virtual bool Pulsado(float x,float y){
		if(x>=this->coord->x&&x<=this->coord->x+this->Wigth&&y>=this->coord->y&&y<=this->coord->y+this->Height)
			return true;
		return false;
	
	};
	virtual bool PulsadoPasivo(int x,int y){
		return Pulsado((float)x,(float)y);
	}
	virtual Type GetPasivePulsado(){return t;};
	virtual bool Escribiendo(){
		return false;};
	virtual char*GetEscritura(){
		return "NULL";};
	virtual bool GetEstoyEscribindo(){return false;}
	virtual void NewCRD(CRD*crd){};
	virtual void AddText(char letra){};
	virtual void AddNewText(char*newTexts){};
	virtual void SubText(){};
	virtual void NoClick(){};
	virtual void SetCoord(float x,float y,float z){
		this->coord->x=x;
		this->coord->y=y;
		this->coord->z=z;
	}
	virtual void SetCoord(CRD*coord){
		this->coord=new CRD(*coord);
	}
	virtual void SetColor(GLfloat R,GLfloat G,GLfloat B){};
	virtual void SetLabelColor(GLfloat R,GLfloat G,GLfloat B){};
	virtual void SetNewProp(float Wigth=0,float Height=0){
		if(Wigth)
		this->Wigth=Wigth;
		if(Height)
		this->Height=Height;
	} 
	virtual void CambiarChecket(){}
	virtual void MoveOnReshape(bool reshape){
		this->reshapeBool=reshape;
	}
	//StackAnimation
	virtual void STANSetAnimation(char*name,CRD coord,float wigth,float height,float TotalWigth,float TotalHeight,float x,float R,float G,float B,float speed){};
	//RadBut
	virtual bool RBGetCheket(){return false;};
	//RadButGroup
	virtual unsigned RBGGetChecket(){return 0;};
	virtual void RBGActivDesactRB(char*name,bool activate){};
	virtual double* RBGGetChecketPositton(){
		double*a=new double[2];
		a[0]=this->coord->x;
		a[1]=this->coord->y;
		return a;};
	virtual void RBGNextChecket(){};
	virtual unsigned RBGGetMaxChecket(){return 0;};
	virtual bool RBGGetRBChecket(char*name){return false;};
	virtual void RBGSetRBChecket(char*RBname,bool checket){};
	virtual void RBGAddRB(char*name,char*escritura,bool Checket=false){};
	virtual void RBGSubRB(char*nameRB){};
	virtual bool RBGGetRBActiveDesavt(char*nameRB){return false;};
	//Box
	virtual unsigned BoxGetElemChecket(){return 0;};
	virtual unsigned BoxGetRBG_RBChecket(char*RBGname,char*RBname){return 0;};
	virtual bool BoxGetRBChecket(char*RBname){return false;};
	virtual unsigned BoxGetRBGChecket(char*RBGname){return 0;};
	virtual bool BoxGetActiveDesact(char*ElementName){return false;};
	virtual bool BoxGetRBGActiveDesact(char*RBGName,char*RBName){return false;};
	virtual void BoxCambiarChecketRB(char*RBname){};
	virtual void BoxSetActivateDesactivate(char*ElementName,bool actvDesact){};
	virtual char* BoxGetEscritura(char*TextBoxname){return new char(0);};
	virtual void BoxNextFocus(){};
	virtual double* BoxFocusClick(){ double*a=new double[2];a[0]=0;a[1]=0;return a;};
	//PURAS
	virtual void Draw()=0; 
	virtual unsigned Click()=0;
};
