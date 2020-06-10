# Git Commands and Workflows #
---------------------------------
Notes on the basic concepts of Git.

*All commands assume that there is a new repro created on GitHub under the `BohlinCywinskiJackson` organization.*

[BCJ organization](https://github.com/BohlinCywinskiJackson/)

## Terms

**RemoteName**: A name given to the folder to sync with.
By default, it should be `origin`.

**RepoName**: The name of the repository added on GitHub for the organization.

**branch**: An independent line of development along the git timeline.
This allows a user to work on a portion of a project without affection portions that are known to work already.
Useful when adding features, repairing bugs, etc.

_Most work should happen on a development branch and **NOT** on the master branch._

**merge**: Combining branches.
Most useful when bringing a development branch onto the Master branch.


## Git Commands

``` bash
# clones GitHub repository to the current folder
git clone /URL/to/repository

# updates local repository from the remote GitHub repository
git pull origin master

# add all changed or new files to the stage to be included with the commit
git add .

# commit all the staged changes with a message for the gitlog
git commit -m "Commit message"

# commit all the staged changes and merge files after conflicts are solved
git commit -a -m "Commit message"

# push commits from the local repository to the remote repository on GitHub
# use the -u flat to remember the local and remote names
git push origin master

# to list all project branches
git branch

# to create a new branch and work on it
git checkout -b <new_branch>

# to work on an existing branch
git checkout <existing_branch>
```

### Typical merge feature

Here the typical pathway to get a development branch created, worked up, then merged back onto master.

```bash
# Start a new feature
git checkout -b new-feature master

# Edit some files
git add <file>
git commit -m "Start a feature"

# Edit some more files
git add <file>
git commit -m "Finish a feature"

# Merge in the new-feature branch
git checkout master

git merge new-feature

git branch -d new-feature
```

## Ignoring files with `.gitignore`

In git, ignore *rules* can be specified to exclude certain files or file types from your commits.
These *rules* are specified in the `.gitignore` file, on the root folder for the whole project or in sub-folders for folder-specific *rules*.

### Ignore file-types

`.gitignore` file to ignore the `.bak` `.dwl` and `.dwl2` file-types:

```
*.bak
*.dwl
*.dwl2
```

### Ignore specific files

`.gitignore` file to ignore specific files named `.DS_Store` and `Thumbs.db`:

```
.DS_Store
Thumbs.db
```
