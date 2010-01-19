#pragma once

#include <QVector>
#include <QImage>
#include <QDomElement>

namespace Poppler
{
    class Page;
}

class Shape;

class Page
{
    public:
        Page(Poppler::Page* ppage = 0);
        
        Poppler::Page* ppage;
        
        QVector<Shape*> shapes;
        
        float scale;
        int dpi;
        
        /** write self into the parent element */
        void write(QDomElement& parent) const;
        
        /** populate self from this element */
        void read(const QDomElement& element);
        
        friend QDataStream& operator << (QDataStream& out, const Page& p);
        friend QDataStream& operator >> (QDataStream& in, Page& p);
                
    private:
};
