# Question 1

$\textbf{Question 1, Part A}$

 $\textbf{1}_n$ is not an eigenvector of $A$. Consider the following counterexample.

Consider the following $3\times3$ column-stochastic matrix

$$
A =
\begin{bmatrix}
0.1883 & 0.6590 & 0.4487 \\
0.7767 & 0.1099 & 0.3786 \\
0.0350 & 0.2311 & 0.1728
\end{bmatrix}
$$

Matrix $A$ was created with the following code:
```matlab
n=3;
A=rand(n,n);
A=A./sum(A);
```

This matrix $A$ satisfies the colum-stochastic properties as all entries are non negative and each colum sums to 1 ($0.1883+0.7767+0.0350=1$, $0.6590+0.1099+0.2311=1$, and $0.4487+0.3786+0.1728=1$)

Let $\textbf{1}_3$ represent a 3-dimensional vector whose entries are all equal to 1, as follows:
$$
\textbf{1}_3 =
\begin{bmatrix}
1\\
1\\
1
\end{bmatrix}
$$

Though trivial, vector $\textbf{1}_n$ was created with the following code:
```matlab
ones_vector=ones(n,1);   % n=3 per the previous code block
```
<br>

We compute $A\textbf{1}_3$ as follows:

$$
A\textbf{1}_3 =
\begin{bmatrix}
0.1883 & 0.6590 & 0.4487 \\
0.7767 & 0.1099 & 0.3786 \\
0.0350 & 0.2311 & 0.1728
\end{bmatrix}
\begin{bmatrix}
1 \\
1 \\
1
\end{bmatrix}
=
\begin{bmatrix}
0.1883 + 0.6590 + 0.4487 \\
0.7767 + 0.1099 + 0.3786 \\
0.0350 + 0.2311 + 0.1728
\end{bmatrix}
=
\begin{bmatrix}
1.2960 \\
1.2651 \\
0.4389
\end{bmatrix}
$$

This was shown above manually, but was originally done with the following code:
```matlab
A*ones_vector
```
<br>

Since $A\textbf{1}_3$ is not a scalar multiple of $\textbf{1}_3$ (the first entry is multiplied by $1.2960$, the second by $1.2651$, and the third by $0.4389$), $\textbf{1}_3$ is not an eigenvector of $A$,

<br>
<br>

$\textbf{Question 1, Part B}$

For any column-stochastic matrix $A$, the product of $A^\top\textbf{1}_3$ always results in $\textbf{1}_n$. This is because each row of the transpose $A^\top$ corresponds to a column of $A$ and each column of the original column-stochastic matrix $A$ sums to 1, by definition.

The following code was run on multiple randomly generated $n\times n$ column-stochastic matrices (~7-8 created with the code outlined in part A) to verify this:
```matlab
A'*ones_vector
```

<br>
<br>

$\textbf{Question 1, Part C}$

The observation from part B (the product of $A^\top\textbf{1}_3$ always results in $\textbf{1}_n$) implies that $\textbf{1}_n$ is an eigenvector of $A^\top$. Since $A^\top\textbf{1}_n=1\cdot\textbf{1}_n$, the eigenvalue is always $\lambda=1$. Since a matrix and its transpose share the same eigenvalues, this also implies that $\lambda=1$ is always an eigenvalue of the original column-stochastic matrix $A$.


<br>

# Question 2

d

<br>


# Question 3

$\textbf{Question 3, Part A}$

The relationship between the eigenvalues of a random matrix $A$ and its transpose $A^\top$ is that they are identical. Several experiments were done, but for brevity only one will be included below.

Based on a random $5\times5$ matrix, the calculated eigenvalues for both $A$ and $A^\top$ are as follows:

| Eigenvalues of $A$           | Eigenvalues of $A^\top$       |
|------------------------------|-------------------------------|
| $3.2037 + 0.0000i$           | $3.2037 + 0.0000i$            |
| $0.5684 + 0.0000i$           | $0.5684 + 0.0000i$            |
| $-0.1026 + 0.5388i$          | $-0.1026 + 0.5388i$           |
| $-0.1026 - 0.5388i$          | $-0.1026 - 0.5388i$           |
| $-0.0457 + 0.0000i$          | $-0.0457 + 0.0000i$           |

This was obtained with the following code:
```matlab
n = 5;
A = rand(n, n);

eigs_of_A = eigs(A);
eigs_of_AT = eigs(A');

[eigs_of_A, eigs_of_AT]
```

For completeness, the matrix $A$ is as follows:
$$
A =
\begin{bmatrix}
0.8147 & 0.0975 & 0.1576 & 0.1419 & 0.6557 \\
0.9058 & 0.2785 & 0.9706 & 0.4218 & 0.0357 \\
0.1270 & 0.5469 & 0.9572 & 0.9157 & 0.8491 \\
0.9134 & 0.9575 & 0.4854 & 0.7922 & 0.9340 \\
0.6324 & 0.9649 & 0.8003 & 0.9595 & 0.6787
\end{bmatrix}
$$
<br>

As shown by the Matlab output, the eigenvalues found for $A$ and $A^\top$ are the have the same real and imaginary components, and are therefore equal.

<br>

$\textbf{Question 3, Part B}$

The eigenvectors of $A$ and $A^\top$ are significantly different.

Consider just the first column, for brevity, of each eigenvector matrix, which correspond to the first eigenvalue provided in part A ($\lambda=3.2037$).

The first eigenvector of $A$ is:
$$
{u}_1=\begin{bmatrix}
-0.2283 + 0.0000i \\
-0.3243 + 0.0000i \\
-0.5141 + 0.0000i \\
-0.5300 + 0.0000i \\
-0.5455 + 0.0000i
\end{bmatrix}
$$

The first eigenvector of $A^\top$ is:
$$
{v}_1=\begin{bmatrix}
0.4680 + 0.0000i \\
0.3988 + 0.0000i \\
0.4633 + 0.0000i \\
0.4523 + 0.0000i \\
0.4503 + 0.0000i
\end{bmatrix}
$$

These vectors neither point in the same direction, nor are scalar multiples of eachother. The same is true for all other eigenvectors.

For the sake of completeness, the matrices of eigenvectors of both $A$ and $A^\top$ are provided below

**Eigenvectors of $A$:**
$$
\begin{bmatrix}
-0.2283 + 0.0000i & -0.5354 + 0.0000i & -0.0179 - 0.1710i & -0.0179 + 0.1710i & -0.1383 + 0.0000i \\
-0.3243 + 0.0000i &  0.1499 + 0.0000i & -0.7077 + 0.0000i & -0.7077 + 0.0000i &  0.4629 + 0.0000i \\
-0.5141 + 0.0000i &  0.7181 + 0.0000i &  0.1450 - 0.3831i &  0.1450 + 0.3831i &  0.3106 + 0.0000i \\
-0.5300 + 0.0000i & -0.4077 + 0.0000i &  0.3302 + 0.3239i &  0.3302 - 0.3239i & -0.7914 + 0.0000i \\
-0.5455 + 0.0000i &  0.0944 + 0.0000i &  0.1645 + 0.2465i &  0.1645 - 0.2465i &  0.2091 + 0.0000i
\end{bmatrix}
$$

**Eigenvectors of $A^\top$:**
$$
\begin{bmatrix}
 0.4680 + 0.0000i & -0.8064 + 0.0000i &  0.2549 - 0.4162i &  0.2549 + 0.4162i & -0.2966 + 0.0000i \\
 0.3988 + 0.0000i &  0.1399 + 0.0000i &  0.2870 + 0.4091i &  0.2870 - 0.4091i &  0.1552 + 0.0000i \\
 0.4633 + 0.0000i &  0.3632 + 0.0000i &  0.2439 - 0.2812i &  0.2439 + 0.2812i &  0.1766 + 0.0000i \\
 0.4523 + 0.0000i &  0.2722 + 0.0000i &  0.0677 + 0.2017i &  0.0677 - 0.2017i &  0.5930 + 0.0000i \\
 0.4503 + 0.0000i & -0.3524 + 0.0000i & -0.5730 + 0.0000i & -0.5730 + 0.0000i & -0.7107 + 0.0000i
\end{bmatrix}
$$

These matrices of eigenvectors were obtained with the following code:
```matlab
[U_A, D_A] = eigs(A);
[U_AT, D_AT] = eigs(A');

disp(U_A);
disp(U_AT);
```

In conclusion, even though the eigenvalues do not change when a matrix is transposed, the eigenvectors and their directions can be significantly different.
<br>


# Question 4

d

<br>


# Question 5

d

<br>


# Question 6

d

<br>


# Question 7

d

<br>

