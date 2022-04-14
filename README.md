<div align="center">

# supersort ⚡

[supersort](https://supersort.website/) is a modern replacement for _sort_.

**README Sections:** [Options](#options) — [Installation](#installation) — [Development](#development)

</div>

---

**supersort** is a modern replacement for the venerable file-listing command-line program `sort` that ships with Unix and Linux operating systems, giving it more features and better defaults.
It uses provides various sorting algorithms like *insertion sort*, *bubble sort*, and *selection sort*.

And it’s **small**, **fast**, and just **one single binary**.

By deliberately making some decisions differently, supersort attempts to be a more featureful, more user-friendly version of `sort`.
For more information, see [supersort’s website](https://supersort.website/).

---

<a id="options">
<h1>Command-line options</h1>
</a>


- **run <command>**: run various sorting algorithms
- **bench**: benchmark various sorting algorithms

---

<a id="installation">
<h1>Installation</h1>
</a>

supersort is available for macOS and Linux.

### Nix

Use nix to install the supersort package from the [tinypkgs](https://github.com/tinypkgs) repository.

    nix profile install github:tiny-technologies/tinypkgs#supersort

### Manual installation from GitHub

Compiled binary versions of supersort are uploaded to GitHub when a release is made.
You can install supersort manually by [downloading a release](https://github.com/tiny-technologies/supersort/releases), extracting it, and copying the binary to a directory in your `$PATH`, such as `/usr/local/bin`.

### Build from source

Compiling supersort is easy, simply run:

```
git clone https://github.com/tiny-technologies/supersort
cd supersort
make
```

### License

[GNU General Public License v3.0](https://github.com/tiny-technologies/supersort/blob/main/LICENSE)
