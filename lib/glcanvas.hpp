/*
Copyright (c) 2016 by Andrew Stroganov <savhte@gmail.com>

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:
Redistributions of source code must retain the above copyright 
notice, this list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright 
notice, this list of conditions and the following disclaimer in 
the documentation and/or other materials provided with the 
distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGE.
*/

// version: 0.2

#ifndef CANVAS_HPP
#define CANVAS_HPP

#define _USE_MATH_DEFINES

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <stdexcept>
#include <memory>
#include "png.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace cnv {

typedef unsigned int color_t;
typedef void (*DisplayFunc)(void);

class ImageImpl
{
public:
	typedef std::shared_ptr<ImageImpl> Ptr;

	ImageImpl(const std::string& name)
	{
		load(name);
	}

	~ImageImpl() { release(); }

	void draw(float x, float y, float size = 1)
	{
//		const int w = glutGet(GLUT_WINDOW_WIDTH);
//		const int h = glutGet(GLUT_WINDOW_HEIGHT);
//		draw(x, y, x+float(width_)/w*size, y + float(height_)/h*size);
		draw(x, y, x+float(width_)*size, y + float(height_)*size);
	}

private:
	ImageImpl(const ImageImpl& );
	ImageImpl& operator=(const ImageImpl&);

//	bool empty() const { return id_ == GL_INVALID_VALUE; }

	void draw(float x1, float y1, float x2, float y2)
	{
		glEnable(GL_TEXTURE_2D);
   		glBindTexture(GL_TEXTURE_2D, id_);
		glBegin(GL_QUADS);
			glTexCoord2d(0, 1); glVertex2f(x1, y2);
			glTexCoord2d(1, 1); glVertex2f(x2, y2);
			glTexCoord2d(1, 0); glVertex2f(x2, y1);
			glTexCoord2d(0, 0); glVertex2f(x1, y1);
		glEnd();
//		glColor3f(1,1,1);
		glDisable(GL_TEXTURE_2D);
	}
	void release()
	{
		//if(empty()) return;
		glDeleteTextures(1, &id_);
		id_ = GL_INVALID_VALUE;
	}

	void load(const std::string& name)
	{
		id_ = GL_INVALID_VALUE;
		std::vector<unsigned char> image;
		const unsigned int error = lodepng::decode(image, width_, height_, name);

		if(error)
		throw std::runtime_error("Can't load image: " + name);

		glGenTextures(1, &id_);
		glBindTexture(GL_TEXTURE_2D, id_);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 	
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);	

		gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width_, height_, GL_RGBA, 
		GL_UNSIGNED_BYTE, &image[0]);		
	}

	unsigned int width_;
	unsigned int height_;
	GLuint id_;
};

class Image
{
public:
	Image()
	{
//		impl_ = ImageImpl::Ptr(new ImageImpl);
	}
	Image(const std::string& name)
	{
		//impl_ = ImageImpl::Ptr(new ImageImpl);
		//impl_->load(name);	
		load(name);
	}

	void draw(float x, float y, float size)
	{
		impl_->draw(x, y, size);
	}	

	void load(const std::string& name)
	{
		impl_ = ImageImpl::Ptr(new ImageImpl(name));
	}

private:

	ImageImpl::Ptr impl_;
};

inline int hexcolor(int r, int g, int b, int alpha = 255)
{
	return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + 
		(alpha & 0xff);
}


inline void color4(int r, int g, int b, int alpha = 255)
{
	glColor4f(float(r)/255, float(g)/255, float(b)/255, float(alpha)/255);
}

inline void color(int c)
{

	color4(
		(c >> 24) & 0xff, 
		(c >> 16) & 0xff,
		(c >> 8) & 0xff,
		c & 0xff
	);
}

inline void position(int x, int y)
{
	glRasterPos2f(x, y);
}

inline void clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

inline void clear(int r, int g, int b, int alpha = 255)
{
	glClearColor(float(r)/255, float(g)/255, float(b)/255, float(alpha)/255); 
	glClear(GL_COLOR_BUFFER_BIT);
}

inline void init()
{
	char* s[1];

	int n = 1;
	s[0] = new char[2];
	s[0][0] = 'c'; s[0][1] = 0;

	glutInit(&n, s);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE);
#ifndef _WIN32
	glEnable(GL_MULTISAMPLE);
#endif
	glEnable( GL_LINE_SMOOTH );
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
}

inline void window(int w = 640, int h = 480)
{
	init();
	glutInitWindowSize(w, h);
	glutCreateWindow("glcanvas");
	gluOrtho2D(0, w, h, 0);
 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glEnable(GL_BLEND); 
	clear(255, 255, 255, 255);
}
//void start(DisplayFunc);

void repaint();

void dot(float x = 0, float y = 0);


namespace detail {
inline void circle(float x, float y, float radius, int c, int vtype)
{
	glBegin(vtype);
	
	color(c);
	float vx = x + radius;
	float vy = y;	

	const int n = 1.5*radius;

	for(int i = 0; i <= n; ++i)
	{
		glVertex2f(vx,vy);
		vx = x + radius*cos(float(i) * 2*M_PI/n);
		vy = y + radius*sin(float(i) * 2*M_PI/n);
		glVertex2f(vx,vy);
	
	}
	glEnd();
}

} //namespace detail


inline void circle(float x, float y, float radius, color_t c = 0x000000ff)
{
	detail::circle(x, y, radius, c, GL_LINES);
}

inline void circle_fill(float x, float y, float radius, color_t c = 0x000000ff)
{
	detail::circle(x, y, radius, c, GL_TRIANGLE_FAN);
}

inline void line(float x1, float y1, float x2, float y2, int c = 0x000000ff)
{
	glBegin(GL_LINES);
		color(c);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
}

inline void rect_fill(float x1, float y1, float x2, float y2, color_t c = 0x000000ff)
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	color(c);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
	glPopMatrix();
}

inline void rect(float x1, float y1, float x2, float y2, int c = 0x000000ff) 
{
	glBegin(GL_LINES);
		color(c);
		glVertex2f(x1, y1);
		glVertex2f(x1, y2);
		glVertex2f(x1, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y2);
		glVertex2f(x2, y1);
		glVertex2f(x2, y1);
		glVertex2f(x1, y1);
	glEnd();
}

class TextOut {};

static TextOut text_out;

inline void print(const std::string& s)
{
	for(size_t i = 0; i < s.size(); ++i)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
		//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
}

template<typename T>
TextOut& operator<<(TextOut& o, const T& v)
{
	std::stringstream str;
	str << v;
	const  std::string& s = str.str();
	print(s);

	return o;
}


inline void sleep(unsigned int ms) {
#ifdef _WIN32
	Sleep(ms);
#else
	// usleep argument must be under 1 000 000
	if (ms > 1000) sleep(ms/1000000);
	usleep((ms % 1000000) * 1000);
#endif
}

inline float frand(float low, float high, float h = 0.00001)
{
	const int m = 0x7fff;
	const float r = rand() % m / float(m - 1);
	return r * (high - low) + low;
}

} // namespace cnv

#endif // CANVAS_HPP
