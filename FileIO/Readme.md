# File Operations in C

## File opening modes

| Feature                                   | r   | r+  | w   | w+  | a   | a+  |
| ----------------------------------------- | --- | --- | --- | --- | --- | --- |
| File contents can be read                 | \*  | \*  |     | \*  |     | \*  |
| File contents can be written              |     |     | \*  | \*  | \*  | \*  |
| File must exist to be opened              | \*  | \*  |     |     |     |     |
| File contents are discarded after opening |     |     | \*  | \*  |     |     |
| Writing always appends new content        |     |     |     |     | \*  | \*  |
