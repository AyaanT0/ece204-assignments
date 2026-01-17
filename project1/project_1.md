# Question 1

$\textbf{Question 1, Part A}$

 $\textbf{1}_n$ is not an eigenvector of $A$. Consider the following counterexample.

Conder the following 3x3 column-stochastic matrix

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

Let
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
ones=ones(n,1)   % n=3 per the previous code block
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
A*ones
```


$\textbf{Question 1, Part B}$

```matlab
A'*ones
```

$\textbf{Question 1, Part C}$



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

