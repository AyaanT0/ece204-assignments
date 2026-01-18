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

To prove that $1_n$ is an eigenvector of $A^\top$ for any $n\times n$ column-stochastic matrix $A$, we need to show that $A^\top1_n=1_n$. Let $A$ have entries $A_{i,j}$. By definition, any column-stochastic matrix must have the sums of the entries in each column $j$ equal 1. Therefore:
$$
\sum_{i = 1}^n a_{i,j} = 1 \quad \text{ for all } j=1,\dots,n
$$

The $(i,j)$ entry of the transpose of A, known as $A^\top$ is $a_{j,i}$. Let $u=A^\top1_n$. The $k^{\text{th}}$ entry of the vector $u$ is caluclated by the summation of the $k^{\text{th}}$ row of $A^\top$ multiplied by the the entries of $1_n$. Therefore:

$$
u_k=
\sum_{j=1}^n(A^\top)_{k,j}\cdot(1_n)_j =
\sum_{j=1}^na_{j,k}\cdot 1
$$

When we swap the indices $i$ and $j$, the sum $\sum_{j=1}^n a_{j,k}=1$ is the sum of the $k^{\text{th}}$ column of the original matrix $A$. Since A is column-stochastic, this sum is equal to 1 for all $k=1,\dots,n$. Formally:
$$
u_k=1 \quad \text{for all }k=1,\dots,n
$$

Since every entry of the resulting vector $u$ is 1, we find that:
$$
A^\top1_n=1_n
$$

Therefore, $1_n$ is an eigenvector of $A^\top$ and it has an eigenvalue $\lambda=1$
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

$\textbf{Question 4, Part A}$

No, not all eigenvalues of a column-stochastic matrix are real. While the entries of a matrix $A$ are real and non-negative, the eigenvalues can be complex. As a counterexample, consider the following $6\times6$ matrix.
$$
A =
\begin{bmatrix}
0.1767 & 0.3187 & 0.0068 & 0.1547 & 0.0618 & 0.2621 \\
0.1096 & 0.1917 & 0.0191 & 0.1877 & 0.1241 & 0.1645 \\
0.1831 & 0.0199 & 0.0749 & 0.1017 & 0.2108 & 0.1472 \\
0.0437 & 0.0783 & 0.2877 & 0.2555 & 0.2628 & 0.1509 \\
0.0598 & 0.1177 & 0.3243 & 0.0648 & 0.0273 & 0.1035 \\
0.4271 & 0.2737 & 0.2871 & 0.2356 & 0.3131 & 0.1718
\end{bmatrix}
$$


The eigenvalues of $A$ are:
$$
\begin{bmatrix}
1.0000 + 0.0000i \\
0.1543 + 0.1477i \\
0.1543 - 0.1477i \\
-0.0106 + 0.0000i \\
-0.2249 + 0.0000i \\
-0.1753 + 0.0000i
\end{bmatrix}
$$

The matrix and eigenvalues were  obtained with the following code:
```matlab
n = 6;
A = rand(n, n);
A = A ./ sum(A);

e = eig(A);

disp(A)
disp(e);
```

Two of the eigenvalues calculated were $\lambda_{2,3}=0.1543\pm0.1477i$. Since these eigenvalues have non zero imaginary components, the statement that all eigenvalues of a column-stochastic matrix are real is false.

<br>

$\textbf{Question 4, Part B}$

No, not all eigenvalues have a positive real component. As a counterexample, consider the same $6\times6$ matrix observed in part A. $\lambda_{4}=-0.0106$.

Consider another example with the following $20\times20$ matrix, which was obtained using the same code in part A (albeit with $n=20$).
$$
A =
\begin{bmatrix}
0.0332 & 0.0307 & 0.0444 & 0.0541 & 0.0497 & 0.0472 & 0.0946 & 0.0606 & 0.0803 & 0.0270 & 0.0129 & 0.0916 & 0.0091 & 0.0655 & 0.0036 & 0.0564 & 0.1129 & 0.0616 & 0.0546 & 0.0677 \\
0.0176 & 0.0554 & 0.0233 & 0.0680 & 0.0379 & 0.0064 & 0.0262 & 0.0565 & 0.0816 & 0.0622 & 0.0318 & 0.0847 & 0.0350 & 0.0313 & 0.0399 & 0.0351 & 0.0754 & 0.0802 & 0.0262 & 0.0451 \\
0.0659 & 0.0869 & 0.0740 & 0.0037 & 0.0222 & 0.0921 & 0.0914 & 0.0520 & 0.0568 & 0.0482 & 0.0747 & 0.1032 & 0.0049 & 0.0590 & 0.0742 & 0.0774 & 0.0268 & 0.0049 & 0.0729 & 0.0667 \\
0.1046 & 0.0624 & 0.0736 & 0.0810 & 0.0648 & 0.0670 & 0.0221 & 0.0270 & 0.0125 & 0.0376 & 0.0805 & 0.0119 & 0.0449 & 0.0657 & 0.0315 & 0.0483 & 0.0467 & 0.0272 & 0.0490 & 0.0713 \\
0.0180 & 0.0350 & 0.0718 & 0.0749 & 0.0197 & 0.0377 & 0.0369 & 0.0244 & 0.0198 & 0.0551 & 0.0714 & 0.0201 & 0.0387 & 0.0254 & 0.0258 & 0.0470 & 0.0141 & 0.0041 & 0.0630 & 0.0415 \\
0.0273 & 0.0312 & 0.0721 & 0.0120 & 0.0055 & 0.1059 & 0.0087 & 0.0443 & 0.0165 & 0.0686 & 0.0010 & 0.0109 & 0.0894 & 0.0434 & 0.0796 & 0.0841 & 0.0311 & 0.0175 & 0.0300 & 0.0550 \\
0.0420 & 0.0472 & 0.0103 & 0.0525 & 0.0661 & 0.0238 & 0.0633 & 0.0224 & 0.0038 & 0.0533 & 0.0868 & 0.0541 & 0.0728 & 0.0770 & 0.0699 & 0.0339 & 0.0299 & 0.0646 & 0.0135 & 0.0435 \\
0.0078 & 0.0441 & 0.0661 & 0.0326 & 0.0578 & 0.0693 & 0.0179 & 0.0790 & 0.0097 & 0.0504 & 0.0949 & 0.0213 & 0.0435 & 0.0432 & 0.0661 & 0.0431 & 0.0384 & 0.0647 & 0.0463 & 0.0020 \\
0.0724 & 0.0375 & 0.0449 & 0.0547 & 0.0616 & 0.0643 & 0.0045 & 0.0968 & 0.0559 & 0.0533 & 0.0793 & 0.0989 & 0.0802 & 0.0260 & 0.0739 & 0.0924 & 0.0176 & 0.0787 & 0.0353 & 0.0337 \\
0.0426 & 0.0583 & 0.0206 & 0.0399 & 0.0553 & 0.0411 & 0.0715 & 0.0029 & 0.0852 & 0.0468 & 0.0044 & 0.0109 & 0.0123 & 0.0487 & 0.0053 & 0.0041 & 0.0403 & 0.0522 & 0.0767 & 0.0488 \\
0.1041 & 0.0775 & 0.0095 & 0.0415 & 0.0361 & 0.0151 & 0.0343 & 0.0526 & 0.0322 & 0.0075 & 0.0389 & 0.0049 & 0.0350 & 0.0284 & 0.0390 & 0.0933 & 0.0141 & 0.0063 & 0.0759 & 0.0394 \\
0.0426 & 0.0443 & 0.0798 & 0.0181 & 0.0337 & 0.0027 & 0.0653 & 0.0085 & 0.0373 & 0.0658 & 0.0725 & 0.0615 & 0.0831 & 0.0595 & 0.0505 & 0.0181 & 0.1024 & 0.0828 & 0.0651 & 0.0281 \\
0.0657 & 0.0448 & 0.0170 & 0.0256 & 0.0703 & 0.0447 & 0.0379 & 0.0787 & 0.0893 & 0.0910 & 0.0751 & 0.0853 & 0.0823 & 0.0325 & 0.0270 & 0.0640 & 0.0109 & 0.0718 & 0.0130 & 0.0708 \\
0.0163 & 0.0130 & 0.0159 & 0.0021 & 0.0273 & 0.0196 & 0.0620 & 0.0971 & 0.0858 & 0.0324 & 0.0231 & 0.0344 & 0.0640 & 0.0387 & 0.0800 & 0.0562 & 0.1077 & 0.0256 & 0.0021 & 0.0626 \\
0.0404 & 0.0025 & 0.0646 & 0.0924 & 0.0702 & 0.0771 & 0.0021 & 0.0066 & 0.0614 & 0.0888 & 0.0277 & 0.0198 & 0.0554 & 0.0546 & 0.0958 & 0.0648 & 0.0462 & 0.0488 & 0.0545 & 0.0641 \\
0.0171 & 0.0303 & 0.0867 & 0.0654 & 0.0680 & 0.0393 & 0.0900 & 0.0922 & 0.0897 & 0.0317 & 0.0692 & 0.0374 & 0.0308 & 0.0765 & 0.0315 & 0.0346 & 0.0055 & 0.0883 & 0.0293 & 0.0281 \\
0.0803 & 0.0331 & 0.0501 & 0.0933 & 0.0734 & 0.0894 & 0.0791 & 0.0018 & 0.0696 & 0.0810 & 0.0491 & 0.0232 & 0.0839 & 0.0258 & 0.0818 & 0.0595 & 0.0396 & 0.0642 & 0.0914 & 0.0448 \\
0.0922 & 0.0682 & 0.0681 & 0.0164 & 0.0436 & 0.0780 & 0.0737 & 0.0671 & 0.0305 & 0.0416 & 0.0642 & 0.0563 & 0.0112 & 0.0659 & 0.0154 & 0.0778 & 0.0852 & 0.0753 & 0.0955 & 0.0659 \\
0.0371 & 0.0999 & 0.0149 & 0.0922 & 0.0548 & 0.0606 & 0.0804 & 0.0769 & 0.0601 & 0.0378 & 0.0243 & 0.1001 & 0.0655 & 0.0581 & 0.0936 & 0.0018 & 0.0920 & 0.0389 & 0.0279 & 0.0705 \\
0.0726 & 0.0977 & 0.0924 & 0.0795 & 0.0819 & 0.0188 & 0.0379 & 0.0524 & 0.0222 & 0.0199 & 0.0182 & 0.0694 & 0.0580 & 0.0750 & 0.0155 & 0.0080 & 0.0631 & 0.0422 & 0.0779 & 0.0505
\end{bmatrix}
$$

The eigenvalues of $A$ are:
$$
\begin{bmatrix}
1.0000 + 0.0000i \\
-0.0699 + 0.1180i \\
-0.0699 - 0.1180i \\
-0.0989 + 0.0000i \\
-0.0646 + 0.0481i \\
-0.0646 - 0.0481i \\
0.0223 + 0.1019i \\
0.0223 - 0.1019i \\
-0.0209 + 0.0698i \\
-0.0209 - 0.0698i \\
-0.0201 + 0.0120i \\
-0.0201 - 0.0120i \\
0.1322 + 0.0000i \\
0.0696 + 0.0529i \\
0.0696 - 0.0529i \\
0.0748 + 0.0226i \\
0.0748 - 0.0226i \\
0.0871 + 0.0000i \\
0.0283 + 0.0176i \\
0.0283 - 0.0176i
\end{bmatrix}
$$

Several of these eigenvalues have negative real components. For instance, $\lambda_{2,3}=-0.0699\pm0.1180i$. Since these real components are negative, the statement that all eigenvalues have a positive real component is false.
<br><br>

$\textbf{Question 4, Part C}$

Across all the trials ($n=6$, $n=20$, and several omitted trials such as $n=10$), I observed that there seems to be an upper bound on the absolute value of the eigenvalues. Specifically, there always seems to be one eigenvalue equal to 1.0000, and the absolute value of every other eigenvalue $\lambda\le1$.

Consider the eigenvalue magnitudes for the $6\times6$ matrix shown in part A.

$$
\begin{bmatrix}
1.0000 \\
0.2136 \\
0.2136 \\
0.0106 \\
0.2249 \\
0.1753
\end{bmatrix}
$$

This was obtained with the following code:
```matlab
disp(abs(e));
```

Consider the following eigenvalue magnitudes for the $20\times20$ matrix provided in part B.
$$
\begin{bmatrix}
1.0000 \\
0.1372 \\
0.1372 \\
0.0989 \\
0.0805 \\
0.0805 \\
0.1043 \\
0.1043 \\
0.0729 \\
0.0729 \\
0.0234 \\
0.0234 \\
0.1322 \\
0.0874 \\
0.0874 \\
0.0781 \\
0.0781 \\
0.0871 \\
0.0334 \\
0.0334
\end{bmatrix}
$$


<br>

# Question 5

To prove that a column-stochastic matrix cannot have an eigenvalue greater than 1, we will assume FTSOC that a column-stochastic matrix $A$ has an eigenvalue $\lambda>1$.

From question 3, we found that a matrix and its transpose share the same eigenvalues. Therefore, is $\lambda>1$ is an eigenvalue of $A$, then $\lambda>1$ is also an eigenvalue of $A^\top$. Therefore, there is an vector $u$ that is nonzero such that:
$$
A^\top u=\lambda u
$$
<br>


# Question 6

$\textbf{Question 6, Part A}$

The sequence coverges to a vector as $k$ increases. To show this, consider the following $5\times5$ column-stochastic matrix $A$:
$$
A =
\begin{bmatrix}
0.609656319939694 & 0.292000724312840 & 0.170857785592720 & 0.160804401127490 & 0.145857084409758 \\
0.027487010132864 & 0.246388405335058 & 0.148588196334060 & 0.146299369190919 & 0.359168274815463 \\
0.239117319368651 & 0.112444468522551 & 0.298110962291621 & 0.212204025906337 & 0.346166681307613 \\
0.039868049092435 & 0.336951713826623 & 0.309670292555400 & 0.232905837557775 & 0.085927241989041 \\
0.083871301466356 & 0.012214688002929 & 0.072772763226199 & 0.247786366217481 & 0.062880717478126
\end{bmatrix}
$$
Consider also the following random initial stochastic vector $u$:
$$
u =
\begin{bmatrix}
0.191121771184060 \\
0.368060185130220 \\
0.130537350572259 \\
0.224449192792449 \\
0.085831500321011
\end{bmatrix}
$$

These were obtained with the following code:
```matlab
format long;
n = 5;
A = rand(n, n);
A = A ./ sum(A);

u = rand(n, 1);
u = u ./ sum(u);
```

The convergence will be checked by calculating the difference between the norms of consecutive iterations as follows: $||A^{101}u-A^{100}u||_{2}$. This difference was found to be $6.3596\times10^{-17}$ ($6.359601310784502\times10^{-17}$ to be more precise). This very small value shows that the values are essentially equal to a high precision.

For completeness, we can observe the vectors after 100 and 101 iterations:
$$
u_{100} =
\begin{bmatrix}
0.327612410621839 \\
0.143514967337518 \\
0.240742772164146 \\
0.188421965803479 \\
0.099707884073018
\end{bmatrix}
\qquad
u_{101} =
\begin{bmatrix}
0.327612410621839 \\
0.143514967337518 \\
0.240742772164146 \\
0.188421965803479 \\
0.099707884073018
\end{bmatrix}
$$

As shown, the vectors are identical to a very high degree of precision, which shows that they are convergent. Additionally, $A^{k}u$ is still a stochastic vector for all k, and the sum of the entries of $A^{100}u$ is exactly $1.000000000000000$. Analysis was done with several increasing values of $k$ (i.e. $k=5$, $k=10$, $k=25$, $k=40$, and $k=75$), but these are omitted for brevity.

This analysis was done by the following code:
```matlab
u_100 = A^100 * u;
u_101 = A^101 * u;

convergence_of_u = norm(u_101 - u_100);
sum_u_100 = sum(u_100);

disp(convergence_of_u)
disp(sum_u_100)
```
<br><br>

$\textbf{Question 6, Part B}$

The sequence $A^{k}v$ also converges when an initial vector $v$ is prescribed. Let $v$ be the following stochastic vector:
$$
v =
\begin{bmatrix}
1 \\
0 \\
0 \\
0 \\
0
\end{bmatrix}
$$

This vector was created with the following code:
```matlab
v = zeros(n, 1);
v(1) = 1;
```

Using the same matrix $A$ from part A, the same analysis was done and the sequence converged with a difference of $||A^{101}v-A^{100}v||_{2}=1.177569344012831\times10^{-16}$. For completeness, we can observe the resulting vectors after iteration:
$$
v_{100} =
\begin{bmatrix}
0.327612410621839 \\
0.143514967337518 \\
0.240742772164146 \\
0.188421965803479 \\
0.099707884073018
\end{bmatrix}
\qquad
v_{101} =
\begin{bmatrix}
0.327612410621839 \\
0.143514967337518 \\
0.240742772164146 \\
0.188421965803479 \\
0.099707884073018
\end{bmatrix}
$$
The code to iterate and perform the analysis is below:
```matlab
v_100 = A^100 * v;
v_101 = A^101 * v;

convergence_of_v = norm(v_101 - v_100);
sum_v_100 = sum(v_100);

disp(convergence_of_v);
```

The resulting vector $A^{k}v$ also remains stochastic, with a sum of exactly $1.000000000000000$.
<br><br><br>
$\textbf{Question 6, Part C}$

Regardless of the initial stochastic vector ($u$ or $v$), the sequences $A^{k}u$ and $A^{k}v$ converge to the same vector. To confirm this, the norm of the difference between the two resulting vectors at $k=100$ was calculated to be $8.326672684688674e-17$. This shows that for a column-stochastic matrix, the convergence behavior is independent of the initial starting vector.

This was calculated with the following code:
```matlab
diff = norm(u_100 - v_100);
disp(diff);
```

<br>

# Question 7

$\textbf{Question 7, Part A}$

The vector that the sequence $A^{k}u$ converges to is the (normalized) eigenvector of $A$ with an eigenvalue of $\lambda=1$. As we observed in question 1, $A^{\top}1_{n}=1_n$ is true for column-stochastic matrices, which means that $\lambda=1$ is always an eigenvalue of $A^\top$ Since a matrix and its transpose share the same eigenvalues, $A$ also has an eigenvalue of $\lambda=1$. $A^{k}u$ converges to a vector $w$ such that $Aw=w$, which is the definition of an eigenvector where $Aw=1\cdot w$.
<br><br>

$\textbf{Question 7, Part B}$

For the wireless sensor mentioned in the introduction, the matrix is:
$$
A=
\begin{bmatrix}
0.4 & 0.1 \\
0.6 & 0.9
\end{bmatrix}
$$

To find the steady state of the system, we need to find the eignevector $x=\begin{bmatrix}x_1\\x_2\end{bmatrix}$ such that $Ax=x$. In other words, $(A-I)x=0$.

Trivially, $\begin{bmatrix}0.4 & 0.1 \\ 0.6 & 0.9\end{bmatrix}-\begin{bmatrix}1 & 0 \\ 0 & 1\end{bmatrix}=\begin{bmatrix}-0.6 & 0.1 \\ 0.6 & -0.1\end{bmatrix}$, therefore:

$$
\begin{bmatrix}
-0.6 & 0.1 \\
0.6 & -0.1
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2
\end{bmatrix}
=
\begin{bmatrix}
0 \\
0
\end{bmatrix}
$$

This leads to the following two equations
$$
\begin{align*}
-0.6x_1 + 0.1x_2 &= 0 \\
0.6x_1 - 0.1x_2 &= 0
\end{align*}
$$

Equation 2 is just $-1$ times equation 1, so there really is only one independent equation. We now have the relationship $6x_1=x_2$ to consider, after rearranging the equation and multiplying both sides by 10. Since the vector must be stochastic ($x_1+x_2=1$), we can substitute to find the following:
$$
\begin{align*}
x_1 + x_2 &= 1 \\
x_1 + 6x_1 &= 1 \\
7x_1 &= 1 \\
x_1 &= \frac{1}{7} \approx 0.14285714285
\end{align*}
$$

It follows that:
$$
\begin{align*}
x_2 &= 6x_1 \\
    &= 6 \cdot \frac{1}{7} = \frac{6}{7} \approx 0.85714285714
\end{align*}
$$

Therefore, the steady state vector is approximately $\begin{bmatrix}0.14285714285 \\ 0.85714285714\end{bmatrix}$. This shows that, when run long term, the sensor transmits approximately $14.3\%$ of the time and is idle approximately $85.7\%$ of the time.
<br><br>

$\textbf{Question 7, Part C}$

Using eigenvalues and eigenvectors of a matrix $A$ is a lot easier than explicitly computing $A^{k}u$ for a few reasons. Firstly, it provides a solution to the long term behavior after solving a single system of linear equations instead of doing hundreds of matrix multiplication operations. Secondly, doing repeated matrix operations could lead to drift or floating point error. Finally, computing $A^k$ is just computationally expensive for large $k$ values, especially if the matrix is very large, but finding the eigenvectors, especially if just the one with eigenvalue $\lambda=1$ (in the case of a column-stochastic matrix), is much quicker and less computaitonally expensive