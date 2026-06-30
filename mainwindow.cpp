#include "MainWindow.h"
#include "Backend.h"

#include <QWebEngineView>
#include <QWebChannel>
#include <QMouseEvent>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    webView = new QWebEngineView(this);
    setCentralWidget(webView);

    backend = new Backend(this);
    channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("backend"), backend);
    webView->page()->setWebChannel(channel);

    webView->load(QUrl(QStringLiteral("qrc:/ui/index.html")));
}

MainWindow::~MainWindow() = default;

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        dragStartPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - dragStartPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    dragging = false;
}