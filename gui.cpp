#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);
    m_state = 0;
    m_timer = new QTimer();

    //Verbinde: Quelle(Timer aus klasse Timer) -> Zeil (Toggel-Funktion aus Klasse Gui)
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);

    m_timer->start(TIMEOUT);
}

void Gui::on_speedSlider_valueChanged(int value)
{
    m_timer->start(1000/value);
}

void Gui::on_blinkButton_clicked()
{
    m_blinkoderlauf = 1;
}

void Gui::on_lauflichtButton_clicked()
{
    m_blinkoderlauf = 0;


    c = 1;
}

void Gui::toggle()
{
    m_state = !m_state;

    label -> setNum(m_state);


    if(m_blinkoderlauf == 1)
    {

        if(m_state == 1)
        {

            c = 15;
        }
        else {

            c = 0;
        }
        m_leds->set(c);
    }

    if(m_blinkoderlauf == 0)
    {
        m_leds->set(c);

            if(c< 8)
            {
                c = c * 2;

            }
            else {
                c = 1;

            }
    }
}
