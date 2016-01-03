#/bin/sh

# adapted from
# https://github.com/edgecase/middleman-gh-pages

DOC_ROOT="$(git rev-parse --show-toplevel)/doc"
BUILD_DIR="$DOC_ROOT/build"
REPO_URL=$(git config --get remote.origin.url)

echo "doc root:   $DOC_ROOT"
echo "build dir:  $BUILD_DIR"
echo "remote url: $REPO_URL"

mkdir -p $BUILD_DIR
cd $BUILD_DIR
git init
git remote add origin $REPO_URL
git fetch origin

git checkout --orphan gh-pages

git fetch origin
git reset --hard origin/gh-pages

cd $DOC_ROOT
bundle exec middleman build --clean

cd $BUILD_DIR
git add --all

git commit -m "auto commit"

git push -f origin gh-pages
git checkout master
git branch -D gh-pages

cd $DOC_ROOT
rm -rf $BUILD_DIR

