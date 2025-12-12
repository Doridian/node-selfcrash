# node-selfcrash

Deliberately crash Node process to simulate native module failure

## Usage

``sh
npm install --save selfcrash
``

``js
const selfcrash = require('selfcrash');
selfcrash.selfcrash(); // Process should now be crashed
``
