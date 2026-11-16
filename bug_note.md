# BUG REPORT
**TREEW Student Records Manager**

**Bug:** Student names containing spaces were not read correctly.

### Description
When entering a name such as "John Smith", the program previously read only "John". This caused problems when adding, searching for, or removing a student by their full name.

### Cause
The program used `cin >> name`, which stops reading when it reaches a space.

### Fix
I added a shared `readFullName()` function that uses `getline(cin >> ws, name)`. This reads the complete name, including spaces, and handles whitespace left by earlier input.

### Result

<table>
<tr>
<td width="75%" valign="middle">

Tested with the name "John Smith":

- Added the student with a score.
- Searched for the full name.
- Removed the student using the full name.

All three operations worked correctly.

</td>
<td width="25%" align="center" valign="middle">
<img src="assets/lain_sleep.gif" width="130" alt="Sleeping Lain">
</td>
</tr>
</table>

**Status:** Resolved and tested.
