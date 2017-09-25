# `C++`:
* In some languages like `Smalltalk` & `Python`, typechecking is done `@ Runtime`.

* `C++` is a **staticaly-typed language**, and type-checking is done **`@ Compile time`**.

Perhaps, the most important feature in `C++` is `CLASS`, which allows users to define their own type.

* **`C++ built-in primitive Types`**:
	
	* **`Arithmetic Types`**:
		* `Integral types`: Character & Boolean types
		* `Floating-point types`: 	
	* **`void`**: 
	
```
C++ Arithmetic Types:
							
1. bool -------- Boolean ------------- NA

2. char -------- Character ----------- 8 bits
3. wchar_t ----- Wide Character ------ 16 bits
4. wchar16_t --- Unicode Character --- 16 bits
5. wchar32_t --- Unicode Character --- 32 bits

6. short ------- Short Integer ------- 16 bits
7. int --------- Integer ------------- 16 bits
8. long -------- Long Integer -------- 32 bits
9. long long --- Long Integer -------- 64 bits

10. float ---------- Single precision floating point ----- 6 significant digits (generally 32 bits)
11. double --------- Double precision floating point ----- 10 significant digits (generally 64 bits)
12. long double ---- Extended precision floating point --- 10 significant digits

These are the minimum required precision of float, double, long double. 
But the actual bits depend on the compilers.
```
* A `char` is guaranteed to be big enough to hold numeric values of the machine's basic character set. So, `char` is same size as machine's single `byte`.

* Except for `bool` and `extended character types`; the `integral types` may be either **`Signed or Unsigned`**.
* By default, `int, short, long, long long` are **`signed`**.
* Use `double` for floating-point computations
* `float` usually does not have enough precision & 
* Cost of double-precision calculation v/s single-precision is negligible. 
Infact in some machines, double-precision calculations are faster.
* If we assign an out-of-range value for an object of **`unsigned`** type, the result is the remainder of value modulo the number of values the target type can hold.
* If we assigned an out-of-range value to an object of **`signed`** type, the result is **undefined**. The program might appear to work or crash or take garbage values.
* If we used both `unsigned` and `int` in an arithmetic operation, then the `int` is implictly converted to `unsigned`.

```c++
unsigned u = 10;
int i = -42;
std::cout << i + i << endl;	// prints -84
std::cout << u + i << endl;	// if 32 bit ints; prints 4294967264
```

* Integer `literals` that begin with `0` are called `octal`.
* Integer `literals` that begin with `0x` or `0X` are called `Hexadecimal`.
```
20	// decimal
024	// octal
0x43	// hexadecimal
0X43	// hexadecimal
```
* By default, `deciaml literals are signed`; while `octal` and `hexadecimal` literals can be either signed or unsigned.
* **There are no literals of type `short`**.

* **`Decimal` literals**:
	* `int`
	* `long`
	* `long long`
	
* **`Octal` & `Hexadecimal` literals**:
	* `int`, `unsigned int`
	* `long`, `unsigned long`
	* `long long`, `unsigned long long`


* By default, the `floating-point literal` has type `double`.
```
'a' ----- a character literal
"a" ----- a string literal
```
* in C++, the compiler appends a `'\0'` to every `string literal`.

```cpp
Escape Sequences in C++ :

newline	--------- \n	double quote ------ \"
vertical tab ---- \v	single quote ------ \'
horizontal tab -- \h	question mark ----- \?
backslash ------- \\	formfeed ---------- \f
backspace ------- \b	carriage return --- \r
```
* `true` and `false` are **bool literals**.
* `nullptr` is a **pointer literal**.
* C++ programers tedn to refer to `variables` as **variables** or **objects** interchangeably.

* **Default Variable Initialization** :
	* The value of an object of built-in type that is not explicitly initialized depends on **where it is defined**.
	* Variables defined **outside a function body** are initialized to **`zero`**.
	* Variables defined **inside a function body** are **`unitialized`**.
	* Uninitialized objects of built-in type defined inside a function body have undefined value.
	
* **`Declaration`**: It makes a name known to the program.
* **`Definition`** : It creates an associated entity. It provides name, type & storage and may also assign some initial value to the entity.
* Any Declaration that has an initializer is a definition.

* **`extern`** :  To obtain a declaration that is not definition we use the keyword `extern`.
	* An `extern` that has an initializer is a Definition.
	* Its an ERROR to privide an initializer on an `extern` **inside a function**.
```c++
extern int i; 		 // it declares but doesnot define i.
int j; 			 // it declares & defines j. 

extern int k = 1234; 	 // k = 1234; initlization overrides the extern keyword.

//---------------------------------
public void functionA(.....){
	......
	extern double my_double = 2.17;		// ERROR; initialization not allowed on an extern inside a function
	......
}
//---------------------------------
```

* Variables must be defined exactly once but can be declared multiple times.
* To use the same variable in multiple files, we must **declare** the variable in all files but **define** that variable in one-and-only-one file.

* **`IDENTIFIERS`**:
	* Can be composed of `letters`, `digits`, & `undersore character`.
	* Must begin with either `letter` or `underscore`.
	* User-defined identifiers cannot contain two `underscore` characters.
	* User-defined identifiers cannot begin with `underscore` followed by an UPPERCASE letter.
	* Identifiers defined **outside a function** may not begin with `underscore`.
	

```
C++ Keywords:

alignas		else		public			unsigned
alignof		enum		register		using
asm		explicit	reinterpret_cast	
auto		export		return			virtual
bool		extern		short			void
break		false		signed			volatile
case		float		sizeof			wchar_t
catch		for		static			while
char		friend		static_assert
char16_t	goto		static_cast
char32_t	if		struct
class		inline		switch
const		int		template
constexpr	long		this
const_cast	mutable		thread_local
continue	namespace	throw
decltype	new		true
default		noexcept	try
delete		nullptr		typedef
do		operator	typeid
double		private		typename
dynamic_cast	protected	union

//----------------------------------------------

C++ Alternative operator names:

and		not
and_eq		not_eq
bitand		or
bitor		or_eq
compl		xor
not		xor_eq

```
* The global scope has no name. Hence when the scope operator(`::`) has an empty lefthand side, it is a request to fetch the name on the right-hand side from the global scope.

* **COMPOUND TYPES**:
	* References
		* `rvalue`
		* `lvalue`
	* Pointers

* **Refrences**: A reference is NOT an object. It's just another name for an already existing object.

	When we define a refernce, instead of copying the initializer's value, we **bind** the refernce to its initializer.

	Once initialized, a refernce remains bound to its initial object.
	There is no way to rebind a refernce to refer to another object.
	As there is no way to rebind a refernce, **`references` must be initialized**.

```c++
int ival = 217;
int &refVal = ival;	// refVal refers to (is another name for) ival
int &refVal2;		// ERROR. references must be initialized.

// REFERENCE IS JUST AN ALIAS

// After a reference is defined, all operations on that reference are actually operations on the object to which it is bound

refVal = 2;	// assigns 2 to the object to which refVal is bound i.e. now, ival = 2;
int ii = refVal;	// same as ii = ival;

int &refVal3 = refVal;	// refVal3 refers to the object to which refVal is bound i.e. ival
int j = refVal3;	// initializes j to same value as ival

```
* The type of refernce and object must be the same.
* A refernce can be bound only to an `object`; not to a `literal` or `an expresion`.

```c++
int &refVal4 = 10;	// ERROR. Reference can't be bount to a literal (10)
double m_dval = 3.14;
int &refVal5 = m_dval;	// ERROR. Reference and object types must match. initializer must be an int type
```

* Because we can't change the value of the `const` object after we create it must be initialized.

```c++
const int i =  get_size();	// OK. initialized at runtime
const int j = 32;		// OK. initialized at compile time
const int k;			// ERROR. k is uninitialized const
```
* To define a single instance of `const` variable that is accessible to other files, we use the `extern` keyword on both its **definition** and **declaration(s)**.
```c++
// file1.cpp 
// define and initializes a const, extern keyword specifies that bufSize is accessible to other files
extern const int bufSize = func();

// file2.cpp 
// here extern specifies that the definition of bufSize is not local its somewhere else
extern const int bufSize;	// same bufSize as defined in file1.cpp
```

* Unlike ordinary references, a **reference to `const`** cannot be used to change the object's value.

```c++
const int bufSize = 217;	// OK.
const int &ref1 = bufSize;	// OK. ref1 is a refernce to const variable bufSize
int &ref2 = bufSize		// ERROR. non-const reference can't refer to a const variable

ref1 = 2491;			// ERROR. refrence to const can't change the object's value
```

* Binding a `reference to const` to a non-`const` object is LEGAL; but the refernce can't be used to change the value of the non-`const` object.

```c++
int i = 217;

int &ref1 = i;		// ref1 is bound to 'i'. ref1 can be used to change the value of 'i'
const int &ref2 = i;	// ref2 is bound to 'i'. BUT ref2 can be used to change value of i
			// b'coz ref2 is a 'refernce to const'

ref1 = 2491;		// OK. ref1 is not const. now, "i = 2491"
ref2 = 1020;		// ERROR. ref2 is a 'refernce to const'. still "i = 2491"
```

* We can define **pointers** that point to either `const` or non-`const`.
* A **pointer to `const`** may not be used to change the object to which it points.
* We may store the address of a `const` object only in a **pointer to `const`**.

```c++
const double pi = 3.14;		// OK. pi is a const double; its value can't be changed
double *ptr = &pi;		// ERROR. non-const pointer(ptr) can't point to a const object (pi)
const double *cptr = &pi;	// OK. only const pointers can store the address of const object

*cptr = 2.17;			// ERROR. cant assign to *cptr
```

* **EXCEPTION**: We can use a **pointer to `const`** to point to a non-`const` object but, can't change the object's value through the pointer.

```c++
double pi = 3.14;	// OK. non-const object
const double *cptr = &pi;	// OK. but cant use cptr to change the value of pi
```
* Like **refernce to `const`**, a **pointer to `const`** says nothing about whether the object to which it points is a `const` or not.

* Unlike references, **pointers** are `object`. So, pointers can be `const` too.
* **`const` pointers**: Like any other `const` objects, a `const pointer` must be initialized & once initialized its value cannot be changed.

```c++
int errNumb = 0;
int *const pErr = &errNumb;	// pErr is a const pointer. pErr will always point to errNumb
const double pi = 3.14;
const double *const pip = &pi;	// pip is a const pointer to a const object
				// neither the value of the object addressed by 'pip' nor the address stored in 'pip' can be changed
				
*pip = 2.17;			// ERROR. pip points to a const object

if (*pErr){			// if the object to which pErr points (i.e. errNumb) is non-zero
	.....
	*pErr = 0;		// OK
	.....
}

```
* **`top-level` & `low-level` `const`**:
* `top-level const`: Used to indicate that the pointer inself is a `const`.
* `low-level const`: When a pointer refers to a `const` object, we refer to that `const` as a low-level `const`.
* The distinction b/w **top-level** and **low-level** matters when we copy an object. 
* When we copy an object, top-level `const` are ignored.
* Wen we copy an object both objects must have same low-level `const` qualifications. **Low-level `const` are never ignored.**

```c++
int i = 0;
int *const p1 = &i;		// const is top-level
const int ci = 42;		// const is top-level
const int *p2 = &ci;		// const is low-level
const int *const p3 = p2;	// rightmost const is top-level; leftmost const is low-level
const int &r = ci;		// const is low-level

//----------------------------------------------------------

i = ci;		// OK copying the value of ci; top-level const in 'ci' ignored
p2 = p3;	// OK. pointed-to type matches; top-level const in 'ci' ignored

//----------------------------------

// When we copy p3 we can ignore its top-level const but not the fact that it points to a const type
// Thus, we can't use p3 to initialize p4 (which points to plain int)

int *p4 = p3;	// ERROR: p3 has a low-level const but p4 doesn't

//-------------------
p2 = p3;	// OK: both p2 and p3 points to the object of same const type

p2 = &i;	// OK. we can convert int* to const int*
int &r = ci;	// ERROR: 'ci' is a const; but r doesn't refer to const
const int &r2 = i;	// OK: can bind const int refernce to a plain int
```

* **`const ` expressions**: 
	* An expression whose value cannot be chnaged.
	* It value can be evaluated at compile time.
	* A `const` object that is initialized from a `const` expression is also a `const` expression
	
* **Variables defined inside a function ordinarily are not stored at fixed address**. Hence we can not use `constexpr` pointers to point to such variables.

* The address of any variable defined outside any function is a constant expression. So we can use `constexpr` pointers to point to such objects.

* When we specify a pointer in a `constexpr` declaration, the `constexpr` specifier applies to the pointer not the type to which the pointer points.
```c++
const int *p = nullptr;		// p is a pointer to a const int
constexpr int *q = nullptr;	// q is a const pointer to int
```
* `constexpr` imposes a top-level `const` on the objects it defines
```c++
constexpr int *np = nullptr;		// np is a const pointer to int that is a null
int j = 0;
constexpr int i = 217;			// i is a const int

// i & j must be defined outside any function
constexpr const int *p1 = &i;		// p1 is a const pointer to a const int i
constexpr int *p2 = &j;			// p2 is a const pointer to an int j
```












































































	
	