```markdown
# Mini-Challenge Write-Up

## 1. Hello Name

### a.
I passed the name as a **command-line argument**. This avoids additional user input and potential buffering issues associated with reading from `stdin`.

### b.
The string was managed using **static allocation**. `argv[1]` refers to memory that is allocated and managed by the operating system at program startup.

---

## 2. Archimedes’ Algorithm

### a.
I timed the program using the macOS **Mach timing API**. `mach_absolute_time()` returns a monotonically increasing tick count, and `mach_timebase_info()` is used to convert those ticks into nanoseconds. The result was then converted into seconds for reporting elapsed time.

### b.
The algorithm converges as expected. The inscribed polygon estimate (`pi_in`) increases toward π, while the circumscribed polygon estimate (`pi_out`) decreases toward π as the number of sides doubles. Minor precision limitations are observed because π cannot be represented exactly using floating-point arithmetic.

---

## 3. Matrix–Vector Multiplication

### a.
The matrix was allocated dynamically as a **one-dimensional array** using `malloc`. It was accessed using row-major indexing with the expression `A[i * columns + j]`.

### b.
Reading the file in the correct order was initially challenging due to the strict format. Using `fscanf` made it easier to read the matrix and vector values sequentially.

### c.
The computation was a standard matrix–vector multiplication. The implementation assumes that the vector length matches the number of matrix columns.

### d.
Timing was performed using `mach_absolute_time()`, measuring only the computation portion of the program.

---

## 4. Arithmetic Operation Comparison

### a.
I used `mach_absolute_time()` to time each operation. For each arithmetic operation, I reset the input variables, recorded a start time, executed a large loop performing that operation, recorded an end time, and computed the elapsed time.

### b.
No, all arithmetic operations are not created equal. Multiplication is typically the fastest, followed by division, then square root, with `sin` being the slowest due to its more complex implementation.

---

## 6. String Transform

### a.
An alternative approach would be to use **dynamic allocation** instead of a fixed-size buffer, allowing the program to handle arbitrarily long input strings.

### b.
There are several potential pitfalls. If a newline character is not encountered, the program may continue reading input until the buffer limit is reached. Additionally, the code assumes that 1024 characters is sufficient; if the input string exceeds this length, it will be truncated.
```
