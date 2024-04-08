// Todescato Tommaso

#include <iostream>

class EnglishTime
{
protected:
    // ora, minuti, secondi >= 0 -> unsigned
    uint32_t ora, minuti, secondi, tempo_totale;

public:
    explicit EnglishTime()
    {
        ora = minuti = secondi = tempo_totale = 0;
    }

    explicit EnglishTime(uint32_t h, uint32_t m, uint32_t s)
    {
        set(h, m, s);
    }

    explicit EnglishTime(uint32_t totale)
    {
        set_total(totale);
    }

    void set(uint32_t h, uint32_t m, uint32_t s)
    {
        this->secondi = s % 60;
        this->minuti = (m + s/60) % 60;
        this->ora = (h + (m + s/60)/60) % 24;

        this->tempo_totale = this->ora*3600 + this->minuti*60 + this->secondi;
    }

    void set_total(uint32_t totale)
    {
        this->secondi = totale % 60;
        this->minuti = (totale/60) % 60;
        this->ora = (totale/3600) % 24;

        this->tempo_totale = totale;
    }

    uint32_t converti(int h, int m, int s)
    {
        return (h*3600 + m*60 + s);
    }

    void reset()
    {
        ora = minuti = secondi = tempo_totale = 0;
    }

    virtual void stampa()
    {
        if (ora < 10) std::cout << '0';
        if (ora < 12) std::cout << ora%12 << "AM" << ':';
        else std::cout << ora%12 << "PM" << ':';

        if (minuti < 10) std::cout << '0';
        std::cout << minuti << ':';

        if (secondi < 10) std::cout << '0';
        std::cout << secondi << std::endl;
    }

    EnglishTime operator+(EnglishTime *t2) const
    {
        uint32_t res = this->tempo_totale + t2->tempo_totale;
        return EnglishTime(res);
    }

    EnglishTime operator-(EnglishTime *t2) const
    {
        if (this->tempo_totale > t2->tempo_totale)
            return EnglishTime(this->tempo_totale - t2->tempo_totale);
        else
            return EnglishTime(0);
    }

    bool operator>=(EnglishTime *t2) const
    {
        return (this->tempo_totale >= t2->tempo_totale);
    }

    bool operator<=(EnglishTime *t2) const
    {
        return (this->tempo_totale <= t2->tempo_totale);
    }

    bool operator!=(EnglishTime *t2) const
    {
        return (this->tempo_totale != t2->tempo_totale);
    }

    bool operator==(EnglishTime *t2) const
    {
        return (this->tempo_totale == t2->tempo_totale);
    }
};

class EuropeTime : public EnglishTime
{
public:
    explicit EuropeTime(uint32_t h, uint32_t m, uint32_t s) : EnglishTime(h, m, s){};
    explicit EuropeTime(uint32_t totale) : EnglishTime(totale){};
    void stampa() override
    {
        if (ora < 10) std::cout << '0';
        std::cout << ora << ':';

        if (minuti < 10) std::cout << '0';
        std::cout << minuti << ':';

        if (secondi < 10) std::cout << '0';
        std::cout << secondi << std::endl;
    }
};

int main()
{
    auto t1 = EnglishTime(3600);
    t1.stampa();
    return 0;
}