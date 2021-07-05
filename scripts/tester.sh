#!/bin/sh

clear

make fclean -C .
make -C .

# START GENERATING LIST OUTPUTS #
./srcs/resources/List/container > ./srcs/resources/List/mio.txt

if [ $? -ne 0 ]
    then
        echo "File mio.txt not found"
fi

./srcs/resources/List/container_orig > ./srcs/resources/List/orig.txt

if [ $? -ne 0 ]
    then
        echo "File orig.txt not found"
fi
# END GENERATING OOUTPUTS #

echo "\n\b\033[36mTesting ft List Container against std List Container\033[0m"

# START DIFF FILE OUTPUTS #
diff ./srcs/resources/List/mio.txt ./srcs/resources/List/orig.txt

if [ $? -eq 0 ]
    then
        echo "\033[32mCheck List is OK: return -> ✅\033[0m"
    else
        echo "\033[31mFor some reason the output files aren't the same -> ❌\033[0m"
fi
# END DIFF #

###################################

#START GENERATING MAP OUTPUTS#
./srcs/resources/Map/container > ./srcs/resources/Map/mio.txt

if [ $? -ne 0 ]
    then
        echo "File mio.txt not found"
fi

./srcs/resources/Map/container_orig > ./srcs/resources/Map/orig.txt

if [ $? -ne 0 ]
    then
        echo "File orig.txt not found"
fi
#END GENERATING OOUTPUTS#

echo "\n\b\033[36mTesting ft Map Container against std Map Container\033[0m"

# START DIFF FILE OUTPUTS #
diff ./srcs/resources/Map/mio.txt ./srcs/resources/Map/orig.txt

if [ $? -eq 0 ]
    then
        echo "\033[32mCheck Map is OK: return -> ✅\033[0m"
    else
        echo "\033[33mFor some reason the output files aren't the same -> ❌\033[0m"
fi
# END DIFF #

###################################

#START GENERATING QUEUE OUTPUTS#
./srcs/resources/Queue/container > ./srcs/resources/Queue/mio.txt

if [ $? -ne 0 ]
    then
        echo "File mio.txt not found"
fi

./srcs/resources/Queue/container_orig > ./srcs/resources/Queue/orig.txt

if [ $? -ne 0 ]
    then
        echo "File orig.txt not found"
fi
#END GENERATING OOUTPUTS#

echo "\n\b\033[36mTesting ft Queue Container against std Queue Container\033[0m"

# START DIFF FILE OUTPUTS #
diff ./srcs/resources/Queue/mio.txt ./srcs/resources/Queue/orig.txt

if [ $? -eq 0 ]
    then
        echo "\033[32mCheck Queue is OK: return -> ✅\033[0m"
    else
        echo "\033[33mFor some reason the output files aren't the same -> ❌\033[0m"
fi
# END DIFF #

###################################

#START GENERATING STACK OUTPUTS#
./srcs/resources/Stack/container > ./srcs/resources/Stack/mio.txt

if [ $? -ne 0 ]
    then
        echo "File mio.txt not found"
fi

./srcs/resources/Stack/container_orig > ./srcs/resources/Stack/orig.txt

if [ $? -ne 0 ]
    then
        echo "File orig.txt not found"
fi
#END GENERATING OOUTPUTS#

echo "\n\b\033[36mTesting ft Stack Container against std Stack Container\033[0m"

# START DIFF FILE OUTPUTS #
diff ./srcs/resources/Stack/mio.txt ./srcs/resources/Stack/orig.txt
if [ $? -eq 0 ]
    then
        echo "\033[32mCheck Stack is OK: return -> ✅\033[0m"
    else
        echo "\033[33mFor some reason the output files aren't the same -> ❌\033[0m"
fi
# END DIFF #

###################################

#START GENERATING VECTOR OUTPUTS#
./srcs/resources/Vector/container > ./srcs/resources/Vector/mio.txt

if [ $? -ne 0 ]
    then
        echo "File mio.txt not found"
fi

./srcs/resources/Vector/container_orig > ./srcs/resources/Vector/orig.txt

if [ $? -ne 0 ]
    then
        echo "File orig.txt not found"
fi

#END GENERATING OOUTPUTS#

echo "\n\b\033[36mTesting ft Vector Container against std Vector Container\033[0m"

# START DIFF FILE OUTPUTS #
diff ./srcs/resources/Vector/mio.txt ./srcs/resources/Vector/orig.txt

if [ $? -eq 0 ]
    then
        echo "\033[32mCheck Vector is OK: return -> ✅\033[0m"
    else
        echo "\033[33mFor some reason the output files aren't the same -> ❌\033[0m"
fi
# END DIFF #

###################################

echo "\n\033[93mContainer tests finished. Check in every container directory the outpus if you wish. /srcs/resources\033[0m\n"
echo "\n\033[93mFor further testing, exec ./tester \033[0m\n"
