// lept_json is a simple json parser library
// provide json data parse,  parse result access, parse result stringify
#ifndef LEPTJSON_H__
#define LEPTJSON_H__
// data type in Json 
typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

// Json's data structure struct with a alias named 'lept_value'
typedef struct {
    lept_type type;
}lept_value;

// Json parse error code 
// enum 中的元素自增
enum {
    LEPT_PARSE_OK = 0,            // parse success
    LEPT_PARSE_EXPECT_VALUE,      // if json data only contains  whitespace
    LEPT_PARSE_INVALID_VALUE,     // input a invalid value
    LEPT_PARSE_ROOT_NOT_SINGULAR  // after whitespace there is still other characters
};

// parser func
// lept_value* v    : is a root of Json tree
// const char* json : is the C Style String for Json data
// return value     : pasre result type  
int lept_parse(lept_value* v, const char* json);

// get parse result data
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
