# node-selfcrash

Deliberately crash Node process to simulate native module failure

## Usage

```sh
npm install --save selfcrash
```

```js
const selfcrash = require('selfcrash');
selfcrash.null_pointer(); // Process should now be crashed
selfcrash.exhaust_memory(); // Will race to allocate as much memory as it can, likely crashing process
```
