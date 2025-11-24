#define ROWS 30
#define COLS 40
#define PERFECT_ROW 24
#define MAX_NOTES 1000
#define MAX_BEATS 1000

typedef struct {
    int row;
    int lane;
    int active;
} Note;