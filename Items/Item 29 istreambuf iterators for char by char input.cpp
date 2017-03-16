/*
 * istreambuf_iterator for character-by-character input
 * 
 * istream_iterator<char>:
 *  - Input iterator that allows you to read char by char from some stream, i.e. an input file stream or cin input stream
 *  - The operator that is used for each char exraction is operator>>
 *      - It carries out a lot of validation
 *      - expensive
 *      - Doesnt copy whitespace
 *      
 * - istreambuf_iterator:
 *  - Gets an iterator to the internal buffer of chars that the stream holds
 *  - Doesnt validate input
 *  - gets white space
 *  - fast
 *
 *
 *
 * Summary:
 *  -
 */