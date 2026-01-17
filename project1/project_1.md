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

d

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

