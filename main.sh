grep -o "#define\\s\\w*" $1 | sort | uniq | sed "s/#define //g"