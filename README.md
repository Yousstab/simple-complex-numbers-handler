# Complex Number Calculator

Personal learning project to practice:
- Multi-file C projects
- Complex number operations
- Memory management
- Menu systems

Work in progress!

# read me future skeleton
(this was taken from my personal notes on Obsidian, I have yet to refine it for github)
  # project complex numbers handler
  take one, two or more complex numbers and do some operations.
  #### sources
  https://en.wikipedia.org/wiki/Complex_number
  #### steps
  - implement one and two complex numbers operations
  - implement equation solver
  - implement more operands with an operation tree etc.
  
  #### notes
  - a complex number is real only and only if it equals its own conjugate.
  - conjugate of a number($z=x+yi,\bar{z}=x-yi \text{ or } z^*$)
  - double conjugate equals the original number
  - $i^2=-1$
  - any complex number can be determined by a couple of numbers, a the real part and b the imaginary. you can also use polar coordinates, angle and magnitude.
  - every polynomial with complex coefficients can be solved with complex numbers.
  - the product between a complex number and its conjugate is a real non negative number, the sum of the squares of the real and imaginary part and it is the square of its absolute value.
  - the magnitude or absolute value is the square root of the sum of the squares of the imaginary and real part
  - by Pythagoras the magnitude is the distance between the point located by the complex number and the origin.
  - the circle of radius r is formed by the numbers z such that |z| = r.
  - if z=x=x+0i is a real number then |z|=|x|: its absolute value as a complex number and as a real number is equal.
  - the reciprocal of a nonzero complex number can be computed as $\frac{1}{z}=\frac{\bar{z}}{\bar{z}z}=\frac{\bar{z}}{|z|^2}=\frac{x-yi}{x^2+y^2}=\frac{x}{x^2+y^2}-\frac{y}{x^2+y^2}i$
  - multiplications between two numbers $z_{1}=a+bi,z_{2}=c+di= (ac-bd)+(ad+bc)i$
  - addition and subtraction(sum or subtract the components)
  - division $w=u+vi,z=x+yi,\frac{w}{z}=\frac{w\bar{z}}{|z|^2}= \frac{(ux+vy)+(vx-uy)i}{x^2+y^2}=\frac{(ux+vy)}{x^2+y^2}+ \frac{(vx-uy)i}{x^2+y^2}$
  - argument can go to any number, principal value only from -pi to pi.
  - $rad:2\pi=\text{degrees}:360$
  - de Moivre  rule: $z^n=(r(\cos(\theta)+i(\sin(\theta)))^n=(r)^n(\cos(n\theta)+i\sin(n\theta))$
  
  #### inline input
  when you want to directly input the complex number without the questions
  format:
  
  
  #### branches
  ##### one number 
  we insert one complex
   real part, imaginary part, cartesian to polar coordinates or viceversa,  absolute value (magnitude) and angle with respect the x axis positive(argument) then store it.
   
  then we have either to calculate:
  input power
  an input root
  its conjugate + sum with conjugate + multiplication with conjugate+ subtraction with conjugate.
  a rotation.
  reciprocal (1/Z)
  
  or display all information.
  in the information we display its normal form, polar form.
  we write out the real, imaginary, argument, principal value and magnitude.
  
  add phasor calculation
  ##### two numbers
  addition or subtraction
  multiplication 
  division
  conjugates display
  
  
  ##### equation solver
  
  #### data structures
  ##### angle_struct
  -argumentInRadians
  -argumentInDegrees
  -principalValueInRadians
  -principalValueInDegrees
  
  ##### complex number 
  -real part
  -imaginary part
  -angle (angle_struct type)
  -magnitude 
  
  ##### angleType enum
  -RADIANS = 0
  -DEGREES = 1
  
  ##### bool enum
  -FALSE = 0
  -TRUE = 1
  
  #### functions
  ##### main
  -handles main menù
  ##### oneComplex
  -calls the setup of the complex number
  -handles the menu for a single complex number
  ##### twoComplex
  -calls the setup for both numbers
  -handles the menu for two complex numbers
  ##### setupComplexNumber
  -handles menu for polar, cartesian coordinate or inline setup
  -calls cartesian polar or inline setup
  ##### displayComplexNumber
  input: pointer to a complex number structure
  -displays the data structure pointer field
  
  ##### degreesToRadians
  input: angle in degrees
  -returns the conversion in radians
  ##### radiansToDegrees
  input: angle in radians 
  -returns the angle in degrees
  ##### principalValueInRadians
  input: angle in radians
  -returns the corresponding principal value between 0 and 2pi (the one without full circle rotations)
  ##### principalValueInDegrees
  input: angle in degrees
  -returns the corresponding principal value between 0 and 360°
  ##### cartesianInput
  input: pointer to complex number
  -asks input for cartesian coordinates
  -calls cartesian setup
  ##### cartesianSetup
  input: pointer to complex number, real part, imaginary part
  -calculates magnitude, argument in radians and degrees, principal values
  -saves all parameters in the complex number structure
  ##### polarInput
  input: pointer to complex number
  -asks input for polar coordinates (magnitude and angle)
  -handles angle type selection (radians/degrees)
  -calls polar setup
  ##### polarSetup
  input: pointer to complex number, magnitude, angle, angleType
  -calculates real and imaginary parts based on polar coordinates
  -calculates all angle representations (argument and principal values)
  -saves all parameters in the complex number structure
  ##### inlineInput
  input: pointer to complex number
  -saves input in the data structure pointer based on [[#inline setup]]
  ##### complexConjugate
  input: complex number pointer, complex conjugate pointer
  -calculates the conjugate parameters based on the complex number data (negates imaginary part)
  -saves the conjugate data in the conjugate pointer using cartesianSetup
  ##### complexRaisePowerDeMoivre
  input: complex number pointer, complex power pointer, power
  -calculates the power of the complex number using De Moivre's formula
  -raises magnitude to the power, multiplies argument by power
  -saves the parameters into complex power pointer using polarSetup
  ##### complexRotate
  input: complex number pointer, complex rotation pointer, angle rotation, type of angle
  -adds rotation angle to the complex number's argument
  -calculates the parameters after rotation
  -saves them in the complex rotation pointer using polarSetup
  ##### complexSum
  input: complex sum pointer, complex number1 pointer, complex number2 pointer
  -adds real parts and imaginary parts separately
  -saves result in complex sum pointer using cartesianSetup
  ##### complexDiff
  input: complex diff pointer, complex number1 pointer, complex number2 pointer
  -subtracts real parts and imaginary parts (first - second)
  -saves result in complex diff pointer using cartesianSetup
  ##### complexMultip
  input: complex multiplication result pointer, complex number1 pointer, complex number2 pointer
  -multiplies using formula: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
  -saves result using cartesianSetup
  ##### complexDiv
  input: complex division result pointer, complex number1 pointer, complex number2 pointer
  -calculates division using reciprocal and multiplication approach
  -calls complexReciprocal on second number, then complexMultip with first number
  -result saved in complex division result pointer
  ##### complexReciprocal
  input: complex number pointer, complex reciprocal pointer
  -calculates reciprocal using formula: 1/z = x/(x²+y²) - yi/(x²+y²)
  -saves result using cartesianSetup
  ##### nonImplementedError
  -outputs an error message
  
  
  #### todo 
  
  ##### single setting setup
  input: settingid, value
  note: need to keep track of setting id
  #### settingsSetup
  input: settings structure
  -change settings
  #### readFileSetup
  input: filename 
  output: settings structure
  -open file read setting 
  -save settings in data struct
  
  #### project structure
  ##### files
  - main.c: contains main program logic, menu handling, input/output functions
  - complexFunctionsLib.c: contains implementation of all complex number operations
  - complexFunctionsLibHeader.h: contains structure definitions, enum definitions, function declarations, constants (PI, E)
  ##### CMakeLists.txt
  - links main.c and complexFunctionsLib.c together
  - compiles to complexnumbershandler executable
  
  #### problems
  might add an angle data structure.
  
  - [ ] other than lacking implementations
  - [x] i noticed that output is written twice both on the exe and on the console of the IDE
  - [ ] add a settings menu for permanent angle type etc.
  - [ ] phasors
  - [x] separate code into library with header file and implementation file
  - [x] implement reciprocal calculation
  - [x] implement division using reciprocal method
  - [x] fix CMake linking issues with library files
  - [x] fix multiple definition errors with enums in header
  - [ ] add division by zero check in complexDiv and complexReciprocal
