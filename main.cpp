#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QPainter>
#include <QPainterPath>
#include <QFont>
#include <QTimer>
#include <QScreen>
#include <cstdlib>

// ---------------------------------------------------------------------------
// BunnyIcon: a small custom-painted widget that draws a simple bunny face
// (two ears + head + eyes) so the UI doesn't depend on emoji font support.
// ---------------------------------------------------------------------------
class BunnyIcon : public QWidget {
public:
    explicit BunnyIcon(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(56, 56);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing, true);

        const QColor furWhite("#FFFFFF");
        const QColor furOutline("#F19BBF");
        const QColor blush("#FF7FAE");

        // Ears
        p.setPen(QPen(furOutline, 2));
        p.setBrush(furWhite);
        p.drawEllipse(QPointF(18, 14), 8, 16);
        p.drawEllipse(QPointF(38, 14), 8, 16);

        // Inner ears
        p.setBrush(blush);
        p.setPen(Qt::NoPen);
        p.drawEllipse(QPointF(18, 15), 4, 10);
        p.drawEllipse(QPointF(38, 15), 4, 10);

        // Head
        p.setPen(QPen(furOutline, 2));
        p.setBrush(furWhite);
        p.drawEllipse(QPointF(28, 34), 20, 18);

        // Eyes
        p.setPen(Qt::NoPen);
        p.setBrush(QColor("#4A2A38"));
        p.drawEllipse(QPointF(21, 32), 2.4, 3.2);
        p.drawEllipse(QPointF(35, 32), 2.4, 3.2);

        // Blush cheeks
        p.setBrush(blush);
        p.drawEllipse(QPointF(17, 39), 3.2, 2.2);
        p.drawEllipse(QPointF(39, 39), 3.2, 2.2);

        // Nose
        p.setBrush(QColor("#E8628F"));
        p.drawEllipse(QPointF(28, 38), 2.2, 1.6);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(600, 380);
    window.setWindowTitle("Create Account");
    window.setStyleSheet("background-color: #F13F82;");

    auto *root = new QVBoxLayout(&window);
    root->setContentsMargins(28, 20, 28, 24);
    root->setSpacing(10);

    // ---- Top bar: back button + bunny icon ----
    auto *topBar = new QHBoxLayout();
    auto *backBtn = new QPushButton("\u2039 back");
    backBtn->setCursor(Qt::PointingHandCursor);
    backBtn->setStyleSheet(
        "QPushButton { color: #FFE1EC; background: transparent; border: none; "
        "font-weight: bold; font-size: 13px; padding: 4px; }"
        "QPushButton:hover { color: #FFFFFF; }"
    );
    topBar->addWidget(backBtn, 0, Qt::AlignLeft);
    topBar->addStretch();
    auto *bunny = new BunnyIcon();
    topBar->addWidget(bunny, 0, Qt::AlignRight);
    root->addLayout(topBar);

    // ---- Title ----
    auto *title = new QLabel("Create Account");
    {
        QFont f = title->font();
        f.setPointSize(19);
        f.setBold(true);
        title->setFont(f);
    }
    title->setAlignment(Qt::AlignHCenter);
    title->setStyleSheet(
        "color: #FFFFFF; background-color: #E8437D; "
        "border-radius: 8px; padding: 4px 14px;"
    );
    auto *titleRow = new QHBoxLayout();
    titleRow->addStretch();
    titleRow->addWidget(title);
    titleRow->addStretch();
    root->addLayout(titleRow);

    // ---- Subtitle ----
    auto *subtitle = new QLabel("sign up and hatch your first bunny friend today!");
    subtitle->setAlignment(Qt::AlignHCenter);
    QFont subFont = subtitle->font();
    subFont.setBold(true);
    subFont.setPointSize(10);
    subtitle->setFont(subFont);
    subtitle->setStyleSheet("color: #FFE1EC; margin-bottom: 6px;");
    root->addWidget(subtitle);

    // ---- Card ----
    auto *card = new QFrame();
    card->setObjectName("card");
    card->setStyleSheet(
        "#card { background-color: #FFD3E0; border-radius: 18px; }"
    );
    auto *cardLayout = new QVBoxLayout(card);
    cardLayout->setContentsMargins(26, 22, 26, 22);
    cardLayout->setSpacing(4);

    QString labelStyle = "color: #B75C82; font-weight: 600; font-size: 12px;";
    QString fieldStyle =
        "QLineEdit {"
        "  background-color: #FF8FB8;"
        "  border: none;"
        "  border-radius: 10px;"
        "  padding: 10px 12px;"
        "  color: #FFFFFF;"
        "  font-size: 13px;"
        "}"
        "QLineEdit::placeholder { color: #FFD6E5; }";

    auto *idLabel = new QLabel("ID/Username");
    idLabel->setStyleSheet(labelStyle);
    cardLayout->addWidget(idLabel);

    auto *idInput = new QLineEdit();
    idInput->setPlaceholderText("Enter your ID/Username");
    idInput->setStyleSheet(fieldStyle);
    idInput->setMinimumHeight(38);
    cardLayout->addWidget(idInput);

    cardLayout->addSpacing(10);

    auto *pwLabel = new QLabel("Password");
    pwLabel->setStyleSheet(labelStyle);
    cardLayout->addWidget(pwLabel);

    auto *pwInput = new QLineEdit();
    pwInput->setPlaceholderText("Enter Password");
    pwInput->setEchoMode(QLineEdit::Password);
    pwInput->setStyleSheet(fieldStyle);
    pwInput->setMinimumHeight(38);
    cardLayout->addWidget(pwInput);

    cardLayout->addSpacing(12);

    // ---- Terms checkbox row ----
    auto *termsRow = new QHBoxLayout();
    auto *agreeBox = new QCheckBox();
    agreeBox->setStyleSheet(
        "QCheckBox::indicator { width: 16px; height: 16px; border-radius: 3px; "
        "border: 2px solid #E8628F; background: #FFFFFF; }"
        "QCheckBox::indicator:checked { background: #E8628F; }"
    );
    auto *termsLabel = new QLabel(
        "I agree to the <a href='#' style='color:#B75C82;'>the Terms of Use</a> "
        "and <a href='#' style='color:#B75C82;'>Privacy</a>"
    );
    termsLabel->setStyleSheet("color: #8C4A68; font-size: 12px;");
    termsLabel->setTextFormat(Qt::RichText);
    termsLabel->setOpenExternalLinks(false);
    termsRow->addWidget(agreeBox, 0, Qt::AlignVCenter);
    termsRow->addWidget(termsLabel, 0, Qt::AlignVCenter);
    termsRow->addStretch();
    cardLayout->addLayout(termsRow);

    cardLayout->addSpacing(14);

    // ---- Submit button ----
    auto *createBtn = new QPushButton("Create Account");
    QFont btnFont = createBtn->font();
    btnFont.setBold(true);
    btnFont.setPointSize(13);
    createBtn->setFont(btnFont);
    createBtn->setCursor(Qt::PointingHandCursor);
    createBtn->setMinimumHeight(44);
    createBtn->setStyleSheet(
        "QPushButton {"
        "  background-color: #FFA6C7;"
        "  color: #C23E73;"
        "  border: none;"
        "  border-radius: 12px;"
        "}"
        "QPushButton:hover { background-color: #FFB6D0; }"
        "QPushButton:pressed { background-color: #F591B8; }"
    );
    cardLayout->addWidget(createBtn);

    root->addWidget(card);

    window.show();

    // If SNAPSHOT_PATH is set, grab a screenshot shortly after showing and quit.
    // This lets us verify the rendered UI headlessly without a real display.
    if (const char *snapPath = std::getenv("SNAPSHOT_PATH")) {
        QTimer::singleShot(200, [&window, snapPath]() {
            QPixmap pix = window.grab();
            pix.save(QString::fromUtf8(snapPath));
            qApp->quit();
        });
    }

    return app.exec();
}