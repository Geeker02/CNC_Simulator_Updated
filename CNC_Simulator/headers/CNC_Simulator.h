#pragma once
#include "Triangulation.h"
#include "BoundingBox.h"
#include <QPushButton>
#include "OpenglWidget.h"
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include "GraphicsSynchronizer.h"

using namespace Geometry;

class CNC_Simulator : public QMainWindow
{
    Q_OBJECT

private:
    void setupUi();
    OpenGlWidget::Data convertTrianglulationToGraphicsObject(const Triangulation& inTriangulation);
    OpenGlWidget::Data convertPolylinesToGraphicsObject(const vector<vector<SurfacePoint>>& polylines);
    OpenGlWidget::Data convertBoundingBoxToGraphicsObject(Triangulation& inTriangulation);
    void readFile(const QString&);

public:
    CNC_Simulator(QWidget *parent = nullptr);
    ~CNC_Simulator();

private slots:
    void onLoadFileClick();
    void onSimulateClick();

private:
    QPushButton* loadFile;
    QPushButton* simulate;
    OpenGlWidget* openglWindowInput;
    OpenGlWidget* openglWindowOutput;

    QVector<GLfloat> vertices;

    GraphicsSynchronizer* graphicsSynchronizer;

private:
    QString inputFilePath;
    QMessageBox msgBox;
    Triangulation inTri;
};
