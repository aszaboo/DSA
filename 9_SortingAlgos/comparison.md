# Sorting Algorithm Comparison

## Time Complexity

| Algorithm      | Best Case        | Average Case      | Worst Case        |
|----------------|------------------|-------------------|-------------------|
| Bubble Sort    | O(n)             | O(n^2)            | O(n^2)            |
| Selection Sort | O(n^2)           | O(n^2)            | O(n^2)            |
| Quick Sort     | O(n log n)       | O(n log n)        | O(n^2)            |
| Merge Sort     | O(n log n)       | O(n log n)        | O(n log n)        |
| Heap Sort      | O(n log n)       | O(n log n)        | O(n log n)        |

## Space Complexity

| Algorithm      | Space Complexity |
|----------------|------------------|
| Bubble Sort    | O(1)             |
| Selection Sort | O(1)             |
| Quick Sort     | O(log n)         |
| Heap Sort      | O(1)             |
| Merge Sort     | O(n)             |

## Real-Time Performance (microseconds)

| Algorithm      | Time (microseconds) |
|----------------|---------------------|
| Bubble Sort    | 2012                |
| Selection Sort | 868                 |
| Heap Sort      | 485                 |
| Merge Sort     | 358                 |
| Quick Sort     | 265                 |

## Detailed Algorithm Explanation and Selection Criteria

### Bubble Sort

**Description**: Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

**When to Use**:

- Small datasets where simplicity is more important than performance.
- Learning purposes to understand basic sorting algorithms.
- When the list is mostly sorted, Bubble Sort may be advantageous due to the early stop condition.

### Selection Sort

**Description**: Selection Sort divides the input list into two parts: a sorted sub-list of items which is built up from left to right at the front (left) of the list and a sub-list of the remaining unsorted items that occupy the rest of the list.

**When to Use**:

- Small datasets.
- When memory usage is a concern and O(1) space complexity is required.

### Quick Sort

**Description**: Quick Sort is a divide-and-conquer algorithm that picks an element as a pivot and partitions the array around the pivot. The process is recursively applied to the sub-arrays.

**When to Use**:

- Large datasets.
- When average-case performance is more important than worst-case performance.
- When O(log n) space complexity is beneficial.

### Merge Sort

**Description**: Merge Sort is a divide-and-conquer algorithm that splits the list into halves, recursively sorts each half, and then merges the sorted halves back together.

**When to Use**:

- Large datasets where stability is required (it is a stable sort).
- External sorting where data is too large to fit into memory (it can work efficiently with external storage).

### Heap Sort

**Description**: Heap Sort involves building a max heap from the input data and then repeatedly extracting the maximum element from the heap and rebuilding the heap.

**When to Use**:

- Large datasets.
- When O(1) space complexity is required.
- When a guaranteed O(n log n) performance is needed, regardless of the initial order of elements.

## Recurrence Relations

### Merge Sort

For Merge Sort, the recurrence relation is:
$$\[ T(n) = 2T\left(\frac{n}{2}\right) + O(n) \]$$
Solving this using the Master Theorem gives:
$$\[ T(n) = O(n \log n) \]$$
This recurrence holds for all cases (best, worst, and average) because Merge Sort always divides the array into two equal halves and the merge step is always linear.

### Quick Sort

For Quick Sort, the recurrence relations are:

- **Best and Average Case**:
$$\[ T(n) = 2T\left(\frac{n}{2}\right) + O(n) \]$$
Solving this using the Master Theorem gives:
$$\[ T(n) = O(n \log n) \]$$
- **Worst Case**:
$$\[ T(n) = T(n-1) + O(n) \]$$
Solving this gives:
$$\[ T(n) = O(n^2) \]$$

## Conclusion

- **For small datasets or simplicity**: Bubble Sort or Selection Sort.
- **For large datasets where worst-case performance needs to be avoided**: Merge Sort.
- **For large datasets where average-case performance is prioritized and space complexity needs to be minimal**: Quick Sort.
- **For large datasets where O(n log n) performance is required and space complexity needs to be minimal**: Heap Sort.
- **For mostly sorted lists**: Bubble Sort (due to early stop condition).

## Quick Reference Table for Algorithm Selection

| Scenario                                     | Recommended Algorithm    |
|----------------------------------------------|--------------------------|
| Small dataset                                | Bubble Sort, Selection Sort |
| Large dataset, worst-case performance critical | Merge Sort               |
| Large dataset, average-case performance prioritized | Quick Sort               |
| Large dataset, space complexity critical      | Heap Sort                |
| Mostly sorted list                            | Bubble Sort (early stop) |

## Arrays Used for Testing

### Unsorted Array

```txt
[166 740 881 241 12 758 21 940 535 743 874 143 717 504 696 762 892 448 698 259 867 352 809 33 727 579 169 504 141 176 433 307 916 314 900 280 424 921 221 960 665 447 455 734 951 151 497 843 600 547 454 819 900 263 204 979 195 725 483 688 901 269 995 170 935 247 450 360 520 23 320 185 822 127 272 773 278 121 969 230 668 423 401 920 39 605 899 234 682 735 922 584 356 269 106 291 516 908 651 36 284 323 574 106 450 198 880 81 319 849 663 339 624 65 260 663 22 511 249 705 598 171 641 954 792 99 246 660 7 249 49 291 925 975 398 727 173 630 160 492 831 824 831 455 889 443 471 263 307 720 320 905 244 961 212 388 60 810 49 68 59 98 711 336 73 109 64 598 91 224 90 922 400 273 730 289 69 201 905 376 273 225 281 869 539 493 258 599 303 659 19 715 757 83 403 182 544 467 780 636 44 222 910 444 847 640 86 916 193 343 292 819 568 926 688 107 771 298 59 427 957 430 494 714 513 897 248 58 717 380 46 113 954 956 909 802 597 995 70 142 690 715 961 611 641 2 718 764 300 129 191 258 912 685 324 425 583 925 835 652 305 881 765 612 838 674 414 787 22 836 929 712 551 243 323 544 245 394 309 897 875 852 155 787 890 832 213 473 757 400 477 414 282 242 26 120 916 792 259 290 629 540 3 532 783 678 429 380 72 90 278 948 942 785 87 832 969 652 657 726 53 134 141 335 728 167 807 645 960 66 935 941 606 290 473 742 969 902 122 393 992 752 693 287 890 781 119 859 433 129 938 486 263 431 821 992 598 980 989 910 46 276 851 5 919 677 747 888 931 869 633 276 974 327 563 864 108 34 75 893 163 13 380 779 796 553 123 747 534 464 657 932 740 861 937 659 890 684 899 821 906 533 449 880 860 12 96 320 47 171 213 562 537 945 341 333 851 464 80 737 928 90 669 21 303 959 680 193 643 932 366 549 465 816 781 677 180 877 997 227 49 562 790 938 508 483 271 359 948 704 448 228 146 117 249 449 76 282 994 72 214 712 973 31 880 107 708 61 984 57 288 385 971 430 323 831 914 947 542 214 3 990 442 149 108 692 950 536 326 296 960 540 8 286 923 889 393 983 950 377 40 590 115 363 373 438 195 287 737 737 501 740 728 295 889 188 987 191 724 313 487 37 205 496 323 128 737 68 111 687 797 503 629 912 867 2 703 62 641 440 799 142 181 527 438 422 67 777 614 792 443 101 181 648 949 856 129 686 276 592 725 73 96 707 986 315 709 689 377 351 129 528 845 662 408 635 85 475 765 699 619 208 152 800 208 102 8 337 140 284 282 866 358 378 925 696 693 634 737 422 337 218 950 535 881 710 170 966 186 287 665 157 847 817 310 56 271 318 745 412 955 27 630 313 757 555 361 802 541 98 224 231 668 527 766 549 237 288 867 775 576 884 933 423 54 243 831 325 913 929 89 868 956 71 181 66 978 894 868 520 344 93 103 13 620 869 914 209 509 782 985 437 18 270 213 72 513 44 398 778 973 839 647 282 911 180 348 889 75 216 761 771 661 864 784 633 85 51 843 595 185 180 32 203 450 245 276 315 290 26 93 615 865 92 249 128 273 597 370 700 166 131 471 827 996 608 461 81 659 656 28 196 836 61 399 638 306 675 305 948 53 750 916 271 843 165 399 116 115 769 816 281 253 639 108 601 247 921 34 258 577 63 454 765 124 854 403 782 881 60 83 287 811 999 558 6 164 309 122 279 431 290 560 684 281 21 285 529 294 319 139 224 382 594 989 858 800 745 641 33 157 724 320 968 75 878 974 239 540 448 871 971 90 783 655 372 156 292 253 451 611 392 675 346 986 16 556 786 113 549 172 271 273 492 591 700 723 566 940 263 366 811 234 457 946 241 181 103 533 434 906 496 826 581 194 165 949 751 303 63 300 475 686 926 968 277 626 43 195 918 306 562 81 892 371 28 133 552 483 18 986 389 514 164 322 61 329 271 164 633 686 464 108 724 742 428 2 721 471 197 991 129 111 73 21 482 453 154 34 936 524 372 325 39 537 647 452 866 270 616 851 309 432 312 33 175 740 387 248 564 585 239 693 696 312 715 531 117 221 565 53 746 290 730 137 827 729 589 45 0 205 897 661 989 209 46 164 301 434 764 865 19 4 559 67 668 274 950 786 847 516 191 593 158 922 730 985 651 671 382 3 228 631 16 218 192 63 734 494 497 499 711 868 503 270 287 523 896 238 309]
```

### Sorted Array

```txt
[0 2 2 2 3 3 3 4 5 6 7 8 8 12 12 13 13 16 16 18 18 19 19 21 21 21 21 22 22 23 26 26 27 28 28 31 32 33 33 33 34 34 34 36 37 39 39 40 43 44 44 45 46 46 46 47 49 49 49 51 53 53 53 54 56 57 58 59 59 60 60 61 61 61 62 63 63 63 64 65 66 66 67 67 68 68 69 70 71 72 72 72 73 73 73 75 75 75 76 80 81 81 81 83 83 85 85 86 87 89 90 90 90 90 91 92 93 93 96 96 98 98 99 101 102 103 103 106 106 107 107 108 108 108 108 109 111 111 113 113 115 115 116 117 117 119 120 121 122 122 123 124 127 128 128 129 129 129 129 129 131 133 134 137 139 140 141 141 142 142 143 146 149 151 152 154 155 156 157 157 158 160 163 164 164 164 164 165 165 166 166 167 169 170 170 171 171 172 173 175 176 180 180 180 181 181 181 181 182 185 185 186 188 191 191 191 192 193 193 194 195 195 195 196 197 198 201 203 204 205 205 208 208 209 209 212 213 213 213 214 214 216 218 218 221 221 222 224 224 224 225 227 228 228 230 231 234 234 237 238 239 239 241 241 242 243 243 244 245 245 246 247 247 248 248 249 249 249 249 253 253 258 258 258 259 259 260 263 263 263 263 269 269 270 270 270 271 271 271 271 271 272 273 273 273 273 274 276 276 276 276 277 278 278 279 280 281 281 281 282 282 282 282 284 284 285 286 287 287 287 287 287 288 288 289 290 290 290 290 290 291 291 292 292 294 295 296 298 300 300 301 303 303 303 305 305 306 306 307 307 309 309 309 309 310 312 312 313 313 314 315 315 318 319 319 320 320 320 320 322 323 323 323 323 324 325 325 326 327 329 333 335 336 337 337 339 341 343 344 346 348 351 352 356 358 359 360 361 363 366 366 370 371 372 372 373 376 377 377 378 380 380 380 382 382 385 387 388 389 392 393 393 394 398 398 399 399 400 400 401 403 403 408 412 414 414 422 422 423 423 424 425 427 428 429 430 430 431 431 432 433 433 434 434 437 438 438 440 442 443 443 444 447 448 448 448 449 449 450 450 450 451 452 453 454 454 455 455 457 461 464 464 464 465 467 471 471 471 473 473 475 475 477 482 483 483 483 486 487 492 492 493 494 494 496 496 497 497 499 501 503 503 504 504 508 509 511 513 513 514 516 516 520 520 523 524 527 527 528 529 531 532 533 533 534 535 535 536 537 537 539 540 540 540 541 542 544 544 547 549 549 549 551 552 553 555 556 558 559 560 562 562 562 563 564 565 566 568 574 576 577 579 581 583 584 585 589 590 591 592 593 594 595 597 597 598 598 598 599 600 601 605 606 608 611 611 612 614 615 616 619 620 624 626 629 629 630 630 631 633 633 633 634 635 636 638 639 640 641 641 641 641 643 645 647 647 648 651 651 652 652 655 656 657 657 659 659 659 660 661 661 662 663 663 665 665 668 668 668 669 671 674 675 675 677 677 678 680 682 684 684 685 686 686 686 687 688 688 689 690 692 693 693 693 696 696 696 698 699 700 700 703 704 705 707 708 709 710 711 711 712 712 714 715 715 715 717 717 718 720 721 723 724 724 724 725 725 726 727 727 728 728 729 730 730 730 734 734 735 737 737 737 737 737 740 740 740 740 742 742 743 745 745 746 747 747 750 751 752 757 757 757 758 761 762 764 764 765 765 765 766 769 771 771 773 775 777 778 779 780 781 781 782 782 783 783 784 785 786 786 787 787 790 792 792 792 796 797 799 800 800 802 802 807 809 810 811 811 816 816 817 819 819 821 821 822 824 826 827 827 831 831 831 831 832 832 835 836 836 838 839 843 843 843 845 847 847 847 849 851 851 851 852 854 856 858 859 860 861 864 864 865 865 866 866 867 867 867 868 868 868 869 869 869 871 874 875 877 878 880 880 880 881 881 881 881 884 888 889 889 889 889 890 890 890 892 892 893 894 896 897 897 897 899 899 900 900 901 902 905 905 906 906 908 909 910 910 911 912 912 913 914 914 916 916 916 916 918 919 920 921 921 922 922 922 923 925 925 925 926 926 928 929 929 931 932 932 933 935 935 936 937 938 938 940 940 941 942 945 946 947 948 948 948 949 949 950 950 950 950 951 954 954 955 956 956 957 959 960 960 960 961 961 966 968 968 969 969 969 971 971 973 973 974 974 975 978 979 980 983 984 985 985 986 986 986 987 989 989 989 990 991 992 992 994 995 995 996 997 999]
```
