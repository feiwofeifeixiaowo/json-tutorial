#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    // storage json number type
	double n;
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    LEPT_PARSE_INVALID_VALUE,
    LEPT_PARSE_ROOT_NOT_SINGULAR,
    LEPT_PARSE_NUMBER_TOO_BIG  // number out of range which leptjson can parse
};

int lept_parse(lept_value* v, const char* json);

lept_type lept_get_type(const lept_value* v);

// return number value 
// lept_value* v : struct to storage return value
double lept_get_number(const lept_value* v);

#endif /* LEPTJSON_H__ */
