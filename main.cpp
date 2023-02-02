#include <QtCore>
#include <QtGui>
#include <iostream>

class MainWindow : public QWidget
{


private:
    
    int num_b;
    double num1;
    double num2;
    double result;
    char oper;

    //Buttons
    QLineEdit *display;
    QGridLayout *layout;
    QPushButton *pb_0;
    QPushButton *pb_1;
    QPushButton *pb_2;
    QPushButton *pb_3;
    QPushButton *pb_4;
    QPushButton *pb_5;
    QPushButton *pb_6;
    QPushButton *pb_7;
    QPushButton *pb_8;
    QPushButton *pb_9;
    QPushButton *pb_add;
    QPushButton *pb_subtract;
    QPushButton *pb_multiply;
    QPushButton *pb_divide;
    QPushButton *pb_equals;
    QPushButton *pb_clear;
    QPushButton *pb_decimal;
    QPushButton *pb_close;
    
    //Anlegen der Funktionen
    void pb_num(int num_b);
    void pb_add_clicked();
    void pb_subtract_clicked();
    void pb_multiply_clicked();
    void pb_divide_clicked();
    void pb_equals_clicked();
    void pb_clear_clicked();
    void pb_decimal_clicked();

public:
    MainWindow();
};

MainWindow::MainWindow()
{
    setMinimumSize(700, 350);

    display = new QLineEdit("0", this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(50);

    //Erstellen der Buttons
    pb_0 = new QPushButton("0", this);
    pb_1 = new QPushButton("1", this);
    pb_2 = new QPushButton("2", this);
    pb_3 = new QPushButton("3", this);
    pb_4 = new QPushButton("4", this);
    pb_5 = new QPushButton("5", this);
    pb_6 = new QPushButton("6", this);
    pb_7 = new QPushButton("7", this);
    pb_8 = new QPushButton("8", this);
    pb_9 = new QPushButton("9", this);
    pb_add = new QPushButton("+", this);
    pb_subtract = new QPushButton("-", this);
    pb_multiply = new QPushButton("*", this);
    pb_divide = new QPushButton("/", this);
    pb_equals = new QPushButton("=",this);
    pb_clear = new QPushButton("Clear",this);
    pb_decimal = new QPushButton(".",this);
    pb_close = new QPushButton("close",this);
    

    //Layout der Buttons
    layout = new QGridLayout(this);
    layout->addWidget(display, 0, 0, 1, 4);
    layout->addWidget(pb_7, 1, 0);
    layout->addWidget(pb_8, 1, 1);
    layout->addWidget(pb_9, 1, 2);
    layout->addWidget(pb_divide, 1, 3);
    layout->addWidget(pb_4, 2, 0);
    layout->addWidget(pb_5, 2, 1);
    layout->addWidget(pb_6, 2, 2);
    layout->addWidget(pb_multiply, 2, 3);
    layout->addWidget(pb_1, 3, 0);
    layout->addWidget(pb_2, 3, 1);
    layout->addWidget(pb_3, 3, 2);
    layout->addWidget(pb_subtract, 3, 3);
    layout->addWidget(pb_0, 4, 0);
    layout->addWidget(pb_decimal, 4, 1);
    layout->addWidget(pb_equals, 4, 2);
    layout->addWidget(pb_add, 4, 3);
    layout->addWidget(pb_clear, 5, 0);
    layout->addWidget(pb_close, 5, 3);

    setLayout(layout);

    //Verbinden der Buttons mit ihren Funktionen
    connect(pb_0, &QPushButton::clicked, this, [&](){pb_num(0);});
    connect(pb_1, &QPushButton::clicked, this, [&](){pb_num(1);});
    connect(pb_2, &QPushButton::clicked, this, [&](){pb_num(2);});
    connect(pb_3, &QPushButton::clicked, this, [&](){pb_num(3);});
    connect(pb_4, &QPushButton::clicked, this, [&](){pb_num(4);});
    connect(pb_5, &QPushButton::clicked, this, [&](){pb_num(5);});
    connect(pb_6, &QPushButton::clicked, this, [&](){pb_num(6);});
    connect(pb_7, &QPushButton::clicked, this, [&](){pb_num(7);});
    connect(pb_8, &QPushButton::clicked, this, [&](){pb_num(8);});
    connect(pb_9, &QPushButton::clicked, this, [&](){pb_num(9);});
    connect(pb_decimal, &QPushButton::clicked, this, &MainWindow::pb_decimal_clicked);
    connect(pb_add, &QPushButton::clicked, this, &MainWindow::pb_add_clicked);
    connect(pb_subtract, &QPushButton::clicked, this, &MainWindow::pb_subtract_clicked);
    connect(pb_multiply, &QPushButton::clicked, this, &MainWindow::pb_multiply_clicked);
    connect(pb_divide, &QPushButton::clicked, this, &MainWindow::pb_divide_clicked);
    connect(pb_equals, &QPushButton::clicked, this, &MainWindow::pb_equals_clicked);
    connect(pb_clear, &QPushButton::clicked, this, &MainWindow::pb_clear_clicked);
    connect(pb_close, &QPushButton::clicked, this, &QWidget::close);
}

//Funktionen der Buttons
void MainWindow::pb_num(int num_b){
    std::cout << num_b << "\n";
    if(display->text() == "0")
    {
        display->clear();
    }

    switch(num_b)
		{
		case 0:
			display->insert("0");
        	break;
		case 1:
			display->insert("1");
        	break;
		case 2:
			display->insert("2");
        	break;
		case 3:
			display->insert("3");
        	break;
        case 4:
			display->insert("4");
        	break;
        case 5:
			display->insert("5");
        	break;
        case 6:
			display->insert("6");
        	break;
        case 7:
			display->insert("7");
        	break;
        case 8:
			display->insert("8");
        	break;
        case 9:
			display->insert("9");
        	break;
        }

}

void MainWindow::pb_decimal_clicked()
{
    if(!display->text().contains("."))
    {
        display->insert(".");
    }
}

void MainWindow::pb_add_clicked()
{
    num1 = display->text().toDouble();
    oper = '+';
    display->clear();
}

void MainWindow::pb_subtract_clicked()
{
    num1 = display->text().toDouble();
    oper = '-';
    display->clear();
}

void MainWindow::pb_multiply_clicked()
{
    num1 = display->text().toDouble();
    oper = '*';
    display->clear();
}

void MainWindow::pb_divide_clicked()
{
    num1 = display->text().toDouble();
    oper = '/';
    display->clear();
}

void MainWindow::pb_equals_clicked()
{
    num2 = display->text().toDouble();

    switch(oper)
		{
		case '+':
			display->setText(QString::number(num1+ num2));
        	break;
		case '-':
			display->setText(QString::number(num1 - num2));
        	break;
		case '*':
			display->setText(QString::number(num1 * num2));
        	break;
		case '/':
			display->setText(QString::number(num1 / num2));
        	break;
        default:
        // operator is doesn't match any case constant (+, -, *, /)
            std::cout << "Error! The operator is not correct \n";
            break;
		}
}

void MainWindow::pb_clear_clicked()
{
    display->clear();
    display->setText("0");
    num1 = 0;
    num2 = 0;
    result = 0;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *window = new MainWindow();
    window->show();

    return app.exec();
}