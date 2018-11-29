typedef struct Date {
    int year;
    int month;
    int day;
} Date;

typedef struct Time {
    int hour;
    int minute;
} Time;

typedef enum Mode {
    T, B
} Mode;

typedef struct opalCard {
    int trans_num;
    Date *date;
    Time *time;
    Mode mode;
    char *details;
    int jour_num;
    char *fare_applied;
    float fare;
    float discount;
    float amount;
} opalCard;
