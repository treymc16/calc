A basic language to learn recursive decent parsing. It doesn't support command line io. Each line is evaluately individually but variables can be used on later lines.

# Usage

./calc [filename]

# Grammar

Expression := Term + Expression<br>
Expression := Term - Expression<br>
Expression := Term<br>
Term := Term \* Factor<br>
Term := Term / Factor<br>
Term := Factor<br>
Term := Identifier<br>
Term := [0-9]+<br>
Identifier := [a-zA-Z0-9]+ // must start with letter<br>
