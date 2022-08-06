A basic language to learn recursive decent parsing. It doesn't support command line io. Each line is evaluately individually but variables can be used on later lines.

# Usage

./calc [filename]

# Grammar

Expression := Term + Expression
Expression := Term - Expression
Expression := Term
Term := Term \* Factor
Term := Term / Factor
Term := Factor
Term := Identifier
Term := [0-9]+
Identifier := [a-zA-Z0-9]+ // must start with letter
